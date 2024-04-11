#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <string>
#include <bitset>
#include <memory>
#include <istream>
#include <ostream>
#include <ios>
#include <utility>
#include <iterator>
#include <conio.h>
#include <iomanip>
#include <complex>
#include <list>
#include <stack>
#include <ctime>
#include <time.h>
#include <fstream> 
#include <algorithm> 
#include <deque> 
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <math.h>
#include <string.h>
#define pb push_back
#define ppb pop_back
#define pi 3.141592653589732384626433832795028841971
#define mp make_pair
#define INF 2147483647
#define range(i,a,b)	for(int (i)=a;(i)<(b);(i)++)
#define rep(i,b)	range(i,0,b)
#define rever(i,a,b)	for(int (i)=a;(i)>(b);(i)--)
#define repe(i,b)	rever(i,b,-1)
#define clear(a)	memset((a),0,sizeof(a))
#define foreach(c,itr)	for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make1(i)	int i;cin>>i
#define make2(i,j)	int i,j;cin>>i>>j;
#define make3(i,j,k)	int i,j,k;cin>>i>>j>>k
#define out(s)	cout<<s<<endl
#define outp(s)	cout<<s<<" "
#define enter(i)	rep(j,i)	cout<<endl;
#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>
#define mii map<int,int>
#define msi map<string,int>
#define mib map<int,bool>
#define msb map<string,bool>
#define mpiii map<pii,int>
#define mpiib map<pii,bool>
#define qi queue<int>
#define qs queue<string>
#define qll queue<ll>
#define pqi priority_queue<int>
#define pqll priority_queue<ll>
#define si set<int>
#define ss set<string>
#define sll set<ll>
#define max(a,b)	(a>b?a:b)
#define min(a,b)	(a>b?b:a)
const int maxn=100;
struct wnum
{
    int d[maxn], len;
	void clean() 
	{
		while(len>1&&!d[len-1]) 
		{
			len--;
		}
	}
    wnum() 
	{
		memset(d,0,sizeof(d));
		len=1;
	}
    wnum(int num) 
	{
		*this=num;
	}
	wnum(char* num)
	{
		*this=num;
	}
    wnum operator=(const char*num)
	{
        memset(d,0,sizeof(d));
		len=strlen(num);
        for(int i=0;i<len;i++)
		{
			d[i]=num[len-1-i]-'0';
		}
        clean();
		return *this;
    }
    wnum operator=(int num)
	{
        char s[maxn];
		sprintf(s,"%d",num);
        *this=s;
		return *this;
    }
    wnum operator+(const wnum& w)
	{
        wnum c=*this;
		int i;
        for(i=0;i<w.len;i++)
		{
        	c.d[i]+=w.d[i];
        	if(c.d[i]>9)
			{
				c.d[i]%=10;
				c.d[i+1]++;
			}
		}
		while(c.d[i]>9) 
		{
			c.d[i++]%=10;
			c.d[i]++;
		}
		c.len=max(len,w.len);
		if(c.d[i]&&c.len<=i)
		{
			c.len=i+1;
		}
        return c;
    }
    wnum operator-(const wnum& w)
	{
        wnum c=*this;
		int i;
        for(i=0;i<w.len;i++){
        	c.d[i]-=w.d[i];
        	if(c.d[i]<0)
			{
				c.d[i]+=10;
				c.d[i+1]--;
			}
		}
		while(c.d[i]<0)
		{
			c.d[i++]+=10;
			c.d[i]--;
		}
		c.clean();
		return c;
    }
    wnum operator *(const wnum& w)
	const
	{
        int i,j;
		wnum c;
		c.len=len+w.len; 
        for(i=0;i<w.len;i++)
		{
			for(j=0;j<len;j++)
			{
				c.d[i+j]+=d[i]*w.d[j];
			}
		}
        for(i=0;i<c.len-1;i++)
        {
            c.d[i+1]+=c.d[i]/10;
			c.d[i]%=10;
        }
        c.clean();
		return c;
    }
    wnum operator/(const wnum& w)
	{
    	int i,j;
		wnum c=*this,a=0;
    	for(i=len-1;i>=0;i--)
    	{
    		a=a*10+d[i];
    		for(j=0;j<10;j++)
			{
				if(a<w*(j+1))
				{
					break;
				}
			}
    		c.d[i]=j;
    		a=a-w*j;
    	}
    	c.clean();
    	return c;
    }
    wnum operator%(const wnum& w)
	{ 
    	int i,j;
		wnum a=0;
    	for(i=len-1;i>=0;i--)
    	{
    		a=a*10+d[i];
    		for(j=0;j<10;j++)if(a<w*(j+1)) break;
    		a=a-w*j;
    	}
    	return a;
    }
	wnum operator+=(const wnum& w)
	{
        *this=*this+w;
        return *this;
    }
    wnum operator-=(const wnum& w)
	{
    	*this=*this-w;
    	return *this;
	}
	wnum operator*=(const wnum& w)
	{
		*this=*this*w;
		return *this;
	}
	wnum operator/=(const wnum& w)
	{
		*this=*this/w;
		return *this;
	}
	wnum operator%=(const wnum& w)
	{
		*this=*this%w;
		return *this;
	}
    bool operator <(const wnum& w)
	const
	{
        if(len!=w.len)
		{
			return len<w.len;
		}
        for(int i=len-1;i>=0;i--)
        {
            if(d[i]!=w.d[i])
			{
				return d[i]<w.d[i];
			}
        }
        return false;
    }
    bool operator>(const wnum& w) 
	const
	{
		return w<*this;
	}
    bool operator<=(const wnum& w) 
	const
	{
		return!(w<*this);
	}
    bool operator>=(const wnum& w) 
	const
	{
		return!(*this<w);
	} 
    bool operator!=(const wnum& w)
	const
	{
		return w<*this||*this<w;
	}
    bool operator==(const wnum& w)
	const
	{
		return !(w<*this)&&!(w>*this);
	}
    wnum operator ^(const wnum& w)
	{
    	if(*this==w)	return 0;
    	else return 1;
	}
	wnum operator ^=(const wnum& w)
	{
    	if(*this==w)	*this=0;
    	else *this=1;
	}
};
using namespace std;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
int pt[4][2];
bool ingrid(int a, int b)
{
	return a>=1&&a<=8&&b>=1&&b<=8;
}
bool safe()
{
	rep(i,8)
	{
		if(!ingrid(pt[2][0]+dx[i],pt[2][1]+dy[i]))	continue;
		if(pt[2][0]+dx[i]==pt[3][0] && pt[2][1]+dy[i]==pt[3][1])	return false;
	}
	rep(i,4)
	{
		int x=pt[3][0],y=pt[3][1];
		while(ingrid(x+dx[i],y+dy[i]))
		{
			x+=dx[i];
			y+=dy[i]; 
			if(x==pt[2][0]&&y==pt[2][1])break;
			rep(k,2)
			{
				if(x==pt[k][0]&&y==pt[k][1])return false;
			}
		}
	}
	return true;
}
bool beat()
{
	if(safe())return false;
	int xx=pt[3][0],yy=pt[3][1];
	rep(i,8)
	{
		int x=xx+dx[i],y=yy+dy[i];
		if(!ingrid(x,y))	continue;
		pt[3][0]=x,pt[3][1]=y;
		if(safe())return false;		
	}
	return true;
}
int main(){
	string s;
	rep(i,4){
		cin>>s;
		pt[i][0]=s[0]-'a'+1;
		pt[i][1]=s[1]-'0';
	}
	if(beat())	cout<<"CHECKMATE";
	else	cout<<"OTHER";
	return 0;
}