#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int n, m;
int a[maxn];
set<int> s1, s2, s3;
vector<pii> vec;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", a + i); 
	m = n;
	for(int i = n - 1; i >= 0; --i){
		if(a[i] == 1){ // open a new row
			if(!m){
				puts("-1");
				return 0;
			}
//			printf("%d %d\n", m, i); 
			--m;
			vec.PB(MP(m, i));
			s1.insert(vec.size() - 1);
		}
		else if(a[i] == 2){
			if(s1.empty()){
				puts("-1");
				return 0;
			}
			int p = *s1.begin();
			s1.erase(p);
			vec.PB(MP(vec[p].fst, i));
			s2.insert(vec.size() - 1);
		}
		else if(a[i] == 3){
			--m;
			int p;
			if(!s3.empty()){
				p = *s3.begin();
				s3.erase(p);
			}
			else if(!s2.empty()){
				p = *s2.begin();
				s2.erase(p);
			}
			else if(!s1.empty()){
				p = *s1.begin();
				s1.erase(p);
			}
			else{
				puts("-1");
				return 0;
			}
			vec.PB(MP(m, vec[p].snd));
			vec.PB(MP(m, i));
			s3.insert(vec.size() - 1);
		}
	}
	
	printf("%d\n", vec.size());
	FOR(i, 0, vec.size())
		printf("%d %d\n", vec[i].fst + 1, vec[i].snd + 1);

	return 0;
}