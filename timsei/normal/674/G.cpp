%:pragma GCC optimize("inline")
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int Segment_Size = N * 4;

namespace fastIO{
    #define BUF_SIZE 100005
    #define OUT_SIZE 100005
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:cant recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:cant recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
  

vector < pair <int, int> > Must[Segment_Size];

int L[Segment_Size], R[Segment_Size], n, m, p, a[N], Tag[Segment_Size];

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

vector <pair <int, int> > operator + (vector < pair <int, int> > A, vector <pair <int, int> > B) {
	vector <pair <int, int> > ans;
	ans = A;
	for(register char i = 0; i < (int)B.size(); ++ i) {
		char fl = 0;
		for(char j = 0; j < (char) ans.size(); ++ j) {
			if(ans[j].first == B[i].first) {
				ans[j].second += B[i].second; fl = -1; break;
			}
			else if(ans[j].second < ans[fl].second) fl = j;
		}
		if(fl == -1) continue;
		if(ans.size() < p) {
			ans.push_back(B[i]);
			continue;
		}
		if(ans[fl].second > B[i].second) {
			for(char j = 0; j < (char) ans.size(); ++ j)
			ans[j].second -= B[i].second;
		}
		else {
			int now = ans[fl].second - 1;
			for(char j = 0; j < (char)ans.size(); ++ j) ans[j].second -= now;
			ans[fl] = B[i];
			ans[fl].second -= now;
			Must[0].clear();
			for(char j = 0; j < (char) ans.size(); ++ j) 
			if(j != fl && ans[j].second == 1) {
				continue;
			}
			else Must[0].push_back(ans[j]);
			ans = Must[0];
		}
	}
	return ans;
}

void up(int no) {
	Must[no] = Must[lc] + Must[rc];
}

void pt(int no, int x) {
	Tag[no] = x;
	Must[no].clear();
	Must[no].push_back(make_pair(x, R[no] - L[no] + 1));
	return;
}

void dn(int no) {
	if(!Tag[no]) return;
	pt(lc, Tag[no]);
	pt(rc, Tag[no]);
	Tag[no] = 0;
}

void build(int no, int l, int r) {
	L[no] = l, R[no] = r;
	if(l == r) {
		read(a[l]);
		Must[no].push_back(make_pair(a[l], 1));
		return;
	}
	getmid;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	up(no);
}

void chg(int no, int l, int r, int x) {
	dn(no);
	if(L[no] == l && R[no] == r) {
		pt(no, x);
		return;
	}
	getmid;
	if(l > mid) chg(rc, l, r, x);
	else if(r <= mid) chg(lc, l, r, x);
	else chg(lc, l, mid, x), chg(rc, mid + 1, r, x);
	up(no);
}

vector <pair <int, int> > query(int no, int l, int r) {
	dn(no);
	if(l == L[no] && r == R[no]) {
		return Must[no];
	}
	getmid;
	if(l > mid) return query(rc, l, r);
	else if(r <= mid) return query(lc, l, r);
	else return query(lc, l, mid) + query(rc, mid + 1, r);
}

main(void) {
	read(n); read(m); read(p);
	p = 100 / p;
	build(1, 1, n);
	int q, ty, l, r, x;
	for(q = m; q --;) {
		read(ty);
		if(ty == 1) {
			read(l); read(r); read(x);
			//scanf("%d%d%d", &l, &r, &x);
			chg(1, l, r, x);
		}
		else {
			read(l); read(r);
			//scanf("%d%d", &l, &r);
			vector < pair <int, int> > ans = query(1, l, r);
			print((int)ans.size());
			println();
			//printf("%d\n", ans.size());
			for(register char i = 0; i < (char) ans.size(); ++ i) print(ans[i].first), print(' ');
			println();
			continue;
		}
	}
}