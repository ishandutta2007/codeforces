#include <iostream>
#include <vector>
using namespace std;
int p[100],n;
struct qwq
{
	int l,r,w;
}l[100];
int cnt=0;
inline void qaq()
{
	for(int i=1;i<=n;i++) l[i]={i,i,p[i]};
	cnt=n;
	int now=1;
	while(now<cnt)
	{
		if(l[now].r+1==l[now+1].l&&l[now].w+(l[now].r-l[now].l+1)==l[now+1].w)
		{
			l[now].r=l[now+1].r;
			for(int i=now+1;i<cnt;i++) l[i]=l[i+1];
			--cnt;
		}
		else ++now;
	}
}
struct qwqaq
{
	int a,b,c,d;
};
vector <qwqaq> ans;
inline int gao(int l1,int r1,int l2,int r2)
{
	int a=l1-1,b=r1-l1+1,c=r2-r1,d=n-r2;
	int nxt[100]={};
	for(int i=1;i<=d;i++) nxt[i]=p[n-d+i];
	for(int i=1;i<=c;i++) nxt[i+d]=p[n-d-c+i];
	for(int i=1;i<=b;i++) nxt[i+d+c]=p[n-d-c-b+i];
	for(int i=1;i<=a;i++) nxt[i+d+b+c]=p[i];
	for(int i=1;i<=n;i++) p[i]=nxt[i];
	ans.push_back({a,b,c,d});
}
int main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> p[i];
	qaq();
	while(cnt!=1)
	{
		int flag=0;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=i+1;j<=cnt;j++)
			{
				if(l[i].w==l[j].w+l[j].r-l[j].l+1)
				{
					gao(l[i].l,l[i].r,l[j].l,l[j].r);
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		qaq();
	//	for(int i=1;i<=n;i++) cout << p[i] << ' '; 
	//	puts("");
	}
	cout << ans.size() << "\n";
	for(auto t:ans)
	{
		if(!t.a&&!t.d) cout << 2 << " " << t.b << " " << t.c << "\n";
		else if(!t.a) cout << 3 << " " << t.b << " " << t.c << " " << t.d<< "\n";
		else if(!t.d) cout << 3 << " " << t.a << " " << t.b << " " << t.c << "\n";
		else cout << 4 << " " << t.a << " " << t.b << " " << t.c << " " << t.d << "\n";
	}
	return 0;
}