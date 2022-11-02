#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

string S[105];
int T[100][100], n;
vector<char> V;
int in[105];
queue<int> Q;

bool jebaj(int p, int k, int d)
{
	//printf("qwe %d %d %d\n", p, k, d);
	if(p==k) return true;
	int ind=p;
	while(ind<=k && (int)S[ind].size()<=d) ind++;
	if(ind>k) return true;
	char pop=S[ind][d];
	for(int i=ind+1; i<=k; i++)
	{
		//printf("%d\n", i);
		if((int)S[ind].size()<=d) return  false;
		if(S[i][d]!=pop)
		{
			int x=(int)pop-(int)'a', y=(int)S[i][d]-(int)'a';
			if(T[y][x]) return false;
			//printf("d=%d %c %c\n", d, (char)(x+(int)'a'), (char)(y+(int)'a'));
			T[x][y]=1;
			if(jebaj(ind, i-1, d+1)==0) return false;
			pop=S[i][d];
			ind=i;
		}
	}
	if(jebaj(ind, k, d+1)==0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<n; i++) cin>> S[i];
	if(jebaj(0, n-1, 0)==0)
	{
		cout<< "Impossible\n";
		return 0;
	}
	for(int i=0; i<26; i++)
	{
		for(int j=0; j<26; j++)
		{
			if(T[i][j])
			{
				in[j]++;
				//printf("%d %d\n", i, j);
			}
		}
	}
	for(int i=0; i<26; i++) if(in[i]==0) Q.push(i);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		V.PB(x);
		for(int i=0; i<26; i++)
		{
			if(T[x][i]==1)
			{
				in[i]--;
				if(in[i]==0) Q.push(i);
			}
		}
	}
	if(V.size()<26)
	{
		cout<< "Impossible\n";
		return 0;
	}
	for(int i=0; i<26; i++) cout<< (char)(V[i]+(int)'a');
	cout<< '\n';
	return 0;
}