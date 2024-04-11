#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
#else
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

class mstream
{
private:
    int res=0;
    bool right=0,sign=0,space=0,zero=0;
    int width=0,precision=0,maxwidth=1e6;
    string interval="";
    const char* formstr(bool ri,bool si,bool sp,bool ze,
                        bool wi,bool pr,
                        string ty)
    {
        string f="%";
        if(ri&&right)f+="-";
        if(si&&sign)f+="+";
        if(sp&&space)f+=" ";
        if(ze&&zero)f+="0";
        if(wi)f+="*";
        if(pr)f+=".*";
        f+=ty;
        f+="%s";
        return f.c_str();
    }
public:
    operator int(){return res;}
    mstream(){}
    mstream operator()()
        {res=0;return*this;}
    mstream setright(bool n=1)
        {right=n;return*this;}
    mstream setleft(bool n=1)
        {right=!n;return*this;}
    mstream setsign(bool n=1)
        {sign=n;return*this;}
    mstream notsign(bool n=1)
        {sign=!n;return*this;}
    mstream setspace(bool n=1)
        {space=n;return*this;}
    mstream notspace(bool n=1)
        {space=!n;return*this;}
    mstream setzero(bool n=1)
        {zero=n;return*this;}
    mstream notzero(bool n=1)
        {zero=!n;return*this;}
    mstream setwidth(int n=0)
        {width=n;return*this;}
    mstream setprecision(int n=6)
        {precision=n;return*this;}
    mstream setmaxwidth(int n=1e6)
        {maxwidth=n;return*this;}
    mstream setinterval(string n=" ")
        {interval=n;return*this;}
    mstream notinterval(string n="")
        {interval=n;return*this;}
    mstream operator>>(int& x)
    {
        int r=scanf("%d",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(long long& x)
    {
        int r=scanf("%I64d",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(float& x)
    {
        int r=scanf("%f",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(double& x)
    {
        int r=scanf("%lf",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(char& x)
    {
        int r=scanf("%c",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(string& x)
    {
        char s[maxwidth+1];
        int r=scanf("%s",s);
        if(r!=EOF)
            x=s,res+=r;
        return *this;
    }
    mstream operator<<(int x)
    {
        int r=printf(formstr(1,1,1,1,1,0,"d"),
                     width,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(long long x)
    {
        int r=printf(formstr(1,1,1,1,1,0,"I64d"),
                     width,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(float x)
    {
        int r=printf(formstr(1,1,1,1,1,1,"f"),
                     width,precision,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(double x)
    {
        int r=printf(formstr(1,1,1,1,1,1,"lf"),
                     width,precision,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(char x)
    {
        int r=printf(formstr(1,0,0,1,1,0,"c"),
                     width,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(string x)
    {
        int r=printf(formstr(1,0,0,1,1,1,"s"),
                     width,maxwidth,x.c_str(),interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
};
mstream mstr=mstream();

const int MAXN = 1e5;
const int MAXLIST = MAXN * 2;
const int LOG_MAXLIST = 18;
const int SQRT_MAXLIST = 447;
const int MAXBLOCKS = MAXLIST / ((LOG_MAXLIST+1)/2) + 1;

int n, root;
vector<int> g[MAXN];
int h[MAXN]; // vertex height
vector<int> a; // dfs list
int a_pos[MAXN]; // positions in dfs list
int block; // block size = 0.5 log A.size()
int bt[MAXBLOCKS][LOG_MAXLIST+1]; // sparse table on blocks (relative minimum positions in blocks)
int bhash[MAXBLOCKS]; // block hashes
int brmq[SQRT_MAXLIST][LOG_MAXLIST/2][LOG_MAXLIST/2]; // rmq inside each block, indexed by block hash
int mlog2[2*MAXN]; // precalced logarithms (floored values)

// walk graph
void dfs (int v, int curh) {
	h[v] = curh;
	IFD( mstr<<"h["<<v<<"]="<<curh<<"\n"; )
	a_pos[v] = (int)a.size();
	a.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i)
		if (h[g[v][i]] == -1) {
			dfs (g[v][i], curh+1);
			a.push_back (v);
		}
}

int log (int n) {
	int res = 1;
	while (1<<res < n)  ++res;
	return res;
}

// compares two indices in a
inline int min_h (int i, int j) {
	return h[a[i]] < h[a[j]] ? i : j;
}

// O(N) preprocessing
void build_lca() {
    mem255(h);
    dfs(0,0);
	int sz = (int)a.size();
	block = (log(sz) + 1) / 2;
	int blocks = sz / block + (sz % block ? 1 : 0);

	// precalc in each block and build sparse table
	memset (bt, 255, sizeof bt);
	for (int i=0, bl=0, j=0; i<sz; ++i, ++j) {
		if (j == block)
			j = 0,  ++bl;
		if (bt[bl][0] == -1 || min_h (i, bt[bl][0]) == i)
			bt[bl][0] = i;
	}
	for (int j=1; j<=log(sz); ++j)
		for (int i=0; i<blocks; ++i) {
			int ni = i + (1<<(j-1));
			if (ni >= blocks)
				bt[i][j] = bt[i][j-1];
			else
				bt[i][j] = min_h (bt[i][j-1], bt[ni][j-1]);
		}

	// calc hashes of blocks
	memset (bhash, 0, sizeof bhash);
	for (int i=0, bl=0, j=0; i<sz||j<block; ++i, ++j) {
		if (j == block)
			j = 0,  ++bl;
		if (j > 0 && (i >= sz || min_h (i-1, i) == i-1))
			bhash[bl] += 1<<(j-1);
	}

	// precalc RMQ inside each unique block
	memset (brmq, 255, sizeof brmq);
	for (int i=0; i<blocks; ++i) {
		int id = bhash[i];
		if (brmq[id][0][0] != -1)  continue;
		for (int l=0; l<block; ++l) {
			brmq[id][l][l] = l;
			for (int r=l+1; r<block; ++r) {
				brmq[id][l][r] = brmq[id][l][r-1];
				if (i*block+r < sz)
					brmq[id][l][r] =
						min_h (i*block+brmq[id][l][r], i*block+r) - i*block;
			}
		}
	}

	// precalc logarithms
	for (int i=0, j=0; i<sz; ++i) {
		if (1<<(j+1) <= i)  ++j;
		mlog2[i] = j;
	}
}

// answers RMQ in block #bl [l;r] in O(1)
inline int lca_in_block (int bl, int l, int r) {
	return brmq[bhash[bl]][l][r] + bl*block;
}

// answers LCA in O(1)
int lca (int v1, int v2) {
	int l = a_pos[v1],  r = a_pos[v2];
	if (l > r)  swap (l, r);
	int bl = l/block,  br = r/block;
	if (bl == br)
		return a[lca_in_block(bl,l%block,r%block)];
	int ans1 = lca_in_block(bl,l%block,block-1);
	int ans2 = lca_in_block(br,0,r%block);
	int ans = min_h (ans1, ans2);
	if (bl < br - 1) {
		int pw2 = mlog2[br-bl-1];
		int ans3 = bt[bl+1][pw2];
		int ans4 = bt[br-(1<<pw2)][pw2];
		ans = min_h (ans, min_h (ans3, ans4));
	}
	return a[ans];
}

int main()
{
    int n,q;
    mstr>>n>>q;
    fort1(i,1,n-1)
    {
        int p;
        mstr>>p;
        p--;
        g[p].phb(i);
        g[i].phb(p);
    }
    build_lca();
    for0(i,q)
    {
        int tq[3];
        mstr>>tq[0]>>tq[1]>>tq[2];
        tq[0]--;
        tq[1]--;
        tq[2]--;
        int ans=0;
        for0(j,3)
        {
            int s=tq[(j+0)%3];
            int f=tq[(j+1)%3];
            int t=tq[(j+2)%3];
            int sf=lca(s,f);
            int tf=lca(f,t);
            int ml=max(h[sf],h[tf]);
            int ta1=h[f]-ml;
            int ts=lca(t,s);
            int ta2=max(0,h[ts]-ml);
            int ta=ta1+ta2+1;
            IFD( mstr<<"s="<<s<<" f="<<f<<" t="<<t<<
                       " sf="<<sf<<" tf="<<tf<<
                       " h_sf="<<h[sf]<<" h_tf="<<h[tf]<<
                       " h_f="<<h[f]<<
                       " ml="<<ml<<" ta="<<ta<<"\n"; )
            ans=max(ans,ta);
        }
        mstr<<ans<<"\n";
    }
}