    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define MAXN 200005
    #define ll long long
    struct node
    {
    	int x,y;
    	bool operator<(const node& b)const
    	{
    		if(y==b.y)return x<b.x;
    		return y>b.y;
    	}
    }a[MAXN];
    ll ans;
    int n,m,N,a1[MAXN],s,s1,i,j,k,x[MAXN],t[MAXN];
    bool b[MAXN];
    int ask(int x)
    {
    	int s=0;
    	for(;x;x^=x&-x)s+=t[x];
    	return s;
    }
    int ask(int l,int r)
    {
    	if(l>r)return 0;
    	return ask(r)-ask(l-1);
    }
    int main()
    {
    	scanf("%d",&n);
    	for(i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    	for(i=1;i<=n;i++)x[i]=a[i].x;
    	sort(x+1,x+n+1);
    	m=unique(x+1,x+n+1)-x-1;
    	for(i=1;i<=n;i++)a[i].x=lower_bound(x+1,x+m+1,a[i].x)-x;
    	sort(a+1,a+n+1);
    	for(i=1;i<=n;i=j)
    	{
    		for(j=i,N=0;j<=n&&a[i].y==a[j].y;j++)
    		{
    			if(!b[a[j].x])
    			{
    				s++;
    				b[a[j].x]=1;
    				for(k=a[j].x;k<=m;k+=k&-k)t[k]++;
    			}
    			a1[++N]=a[j].x;
    		}
    		a1[++N]=m+1;
    		ans+=(ll)s*(s+1)>>1;
    		for(k=0;k<N;k++)
    		{
    			s1=ask(a1[k]+1,a1[k+1]-1);
    			ans-=(ll)s1*(s1+1)>>1;
    		}
    	}
    	cout<<ans<<endl;
    	return 0;
    }