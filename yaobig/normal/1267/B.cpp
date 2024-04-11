#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];
int num[maxn+5],c[maxn+5];


int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int N=0;
	rep(i,1,n)
	{
		if(s[i]!=s[i-1])
        {
            c[++N]=s[i];
            num[N]=1;
        }
        else num[N]++;
	}
	if(N%2==0) puts("0");
	else
    {
        int mid=(N+1)/2;
        bool f=num[mid]>=2;
        rep(i,1,N) if(c[i]!=c[N+1-i] || num[i]+num[N+1-i]<3) f=0;
        if(f==0) puts("0");
        else printf("%d\n",num[mid]+1);
    }
	return 0;
}