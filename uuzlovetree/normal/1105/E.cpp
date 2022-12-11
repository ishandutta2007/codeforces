#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> mp;
bool has[42][100005];
int a[42][42];
int p[42];
bool is[42];
int ans,Ans[42];
int main()
{
	scanf("%d%d",&n,&m);
	int last=0,cnt=0;
	for(int i=1;i<=n;++i)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)++last;
		else
		{
			string s;
			cin>>s;
			if(!mp.count(s))mp[s]=++cnt;
			has[mp[s]][last]=1;
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			bool yes=1;
			for(int k=1;k<=last;++k)if(has[i][k]&&has[j][k])yes=0;
			if(yes)a[i][j]=a[j][i]=1;
		}
	}
	for(int i=1;i<=m;++i)p[i]=i;
	srand(time(NULL));
    for(int t=1;t<=3000;++t)
    {
        random_shuffle(p+1,p+m+1);
        memset(is,0,sizeof(is));
        int num=0;
        for(int i=1;i<=m;++i)
        {
            bool ok=1;
            for(int j=1;j<i;++j)if(is[p[j]]&&!a[p[i]][p[j]])ok=0;
            if(ok)is[p[i]]=1,num++;
        }
        if(num>ans)
        {
            ans=0;
            for(int i=1;i<=m;++i)if(is[p[i]])Ans[++ans]=p[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}