#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
    string s[6];
    for(int i=0;i<6;i++) cin>>s[i];
    for(int i=1;i<6;i++)
	{
		if(s[i][0]==s[0][0] || s[i][1]==s[0][1]) return 0*printf("YES\n");
	}
	printf("NO\n");
	return 0;
}