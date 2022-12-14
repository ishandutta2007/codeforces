#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

namespace rmq2d{ // https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnxrYzUwZGh2fGd4OjYwNGQ0OTUwYmU0MmM4MWY

	int const N=1005,NLAY=12;


#define fo(i,a,b)   for(int i=a;i<=b;++i)
#define fd(i,a,b)   for(int i=a;i>=b;--i)
using   namespace   std;
int n,m,Q,X1,Y1,X2,Y2;
int16_t a[N][N],F[N][N][NLAY][NLAY];

//------------------------
int16_t max4(int16_t x1,int16_t x2,int16_t x3,int16_t x4)
{
    return max(max(x1,x2),max(x3,x4));
}
//------------------------
void    RMQ2D()
{
    fd(i,m,1)
        fd(j,n,1)
        {
            F[i][j][0][0]=a[i][j];
            for(int q=1;i+(1<<q)-1<=m;++q)
                F[i][j][q][0]=max(F[i][j][q-1][0],F[i+(1<<(q-1))][j][q-1][0]);
            for(int k=1;j+(1<<k)-1<=n;++k)
                F[i][j][0][k]=max(F[i][j][0][k-1],F[i][j+(1<<(k-1))][0][k-1]);
            for(int q=1;i+(1<<q)-1<=m;++q)
                for(int k=1;j+(1<<k)-1<=n;++k)
                F[i][j][q][k]=max4(F[i][j][q-1][k-1],F[i+(1<<(q-1))][j+(1<<(k-1))][q-1][k-1],
                                   F[i][j+(1<<(k-1))][q-1][k-1],F[i+(1<<(q-1))][j][q-1][k-1]);
        }
}
//------------------------
int get(int x1,int y1,int x2,int y2)
{
    int k=__lg(y2-y1+1);
    int q=__lg(x2-x1+1);
    return max4(F[x1][y1][q][k],F[x2-(1<<q)+1][y2-(1<<k)+1][q][k],
                F[x2-(1<<q)+1][y1][q][k],F[x1][y2-(1<<k)+1][q][k]);
}

#undef fo
#undef fd
};

int main(){
	int nrow,ncol;std::scanf("%d %d",&nrow,&ncol);
	std::vector<std::string> a(nrow);
	for(int r=0;r<nrow;++r){
		a[r].resize(ncol);
		for(char& c:a[r])std::scanf(" %c",&c);
	}

	for(int r=nrow;r--;)
	for(int c=ncol;c--;){
		if(a[r][c]=='0')
			rmq2d::a[r+1][c+1]=0;
		else
			rmq2d::a[r+1][c+1]=1+std::min({
					rmq2d::a[r+1][c+2],
					rmq2d::a[r+2][c+1],
					rmq2d::a[r+2][c+2]
					});
	}

	rmq2d::m=nrow;
	rmq2d::n=ncol;
	rmq2d::RMQ2D();

	int nquery;std::scanf("%d",&nquery);
	for(int z=nquery;z--;){
		int x1,y1,x2,y2;std::scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int maxd=std::min(x2-x1+1,y2-y1+1);
		int d=0;
		for(int step=1<<12;step;step>>=1)if(d+step<=maxd){
			d+=step;
			if(rmq2d::get(x1,y1,x2-d+1,y2-d+1)<d)
				d-=step;
		}
		std::printf("%d\n",d);
	}
}