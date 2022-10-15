#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X(x) string(#x)+"="+to_string((x))

vector<int> *graph;
bool *visited, *small, *active;

void fk() {
	cout << "No";
	exit(0);
}

void dfs(int node, int prev) {
	//cout << "dfs " << node << " " << prev << endl;
	visited[node]=true;
	active[node]=true;
	for(int neighbor : graph[node]) {
		if(neighbor==prev)
			continue;
		if(active[neighbor]) {
			//cout << "fked: cycle with " << node << ", " << neighbor << endl;
			fk();
		}
		if(!visited[neighbor])
			dfs(neighbor, node);
		if(neighbor<node) {
			if(small[neighbor])
				small[node]=true;
		} else {
			if(small[neighbor]) {
				//cout << "fked: small neighbor " << node << "->" << neighbor << endl;
				fk();
			}
			small[node]=true;
		}
	}
	active[node]=false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	graph = new vector<int>[m+1];
	visited = new bool[m+1]();
	small = new bool[m+1]();
	active = new bool[m+1]();
	unordered_set<ll> addedEdges;
	int l1;
	cin >> l1;
	int *s1 = new int[l1];
	for(int i=0; i<l1; ++i)
		cin >> s1[i];
	for(int i=0; i<n-1; ++i) {
		int l2;
		cin >> l2;
		int *s2 = new int[l2];
		for(int j=0; j<l2; ++j)
			cin >> s2[j];
		for(int j=0; j<=l1; ++j) {
			if(j>=l1)
				break;
			if(j>=l2) {
				//cout << "fked: prefix after word" << endl;
				fk();
			}
			if(s1[j]==s2[j])
				continue;
			ll eH = (ll)s2[j]*(m+1)+s1[j];
			if(addedEdges.find(eH)==addedEdges.end()) {
				graph[s2[j]].push_back(s1[j]);
				addedEdges.insert(eH);
			}
			break;
		}
		l1=l2;
		s1=s2;
	}
	for(int i=1; i<=m; ++i)
		if(!visited[i])
			dfs(i, 0);
	cout << "Yes\n";
	vector<int> capLetters;
	for(int i=1; i<=m; ++i)
		if(!small[i])
			capLetters.push_back(i);
	cout << capLetters.size() << "\n";
	for(int capLet : capLetters)
		cout << capLet << " ";
}