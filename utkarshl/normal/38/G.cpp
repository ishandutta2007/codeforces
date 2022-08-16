#include"vector"
#include"stdio.h"
#include"algorithm"
#define C 300
using namespace std;
vector<vector<int> > I;
vector<int> maxSegment,sizeSegment;
int A[100000],B[100000];
char Arr[10000];
void print()
{
//	Arr[0]=0;
	for(int x=0;x<I.size();x++)
	{
		for(int j=0;j<sizeSegment[x];j++)
		{
			printf("%d ",I[x][j]+1);
		}
//		sprintf(Arr,"%s| ",Arr);
	}
//	return Arr;
}
void insert_back(int i)
{
	int l=I.size()-1,skipped=0;
//	print();
	while(l && maxSegment[l]<A[i] && skipped+sizeSegment[l]<=B[i] )skipped+=sizeSegment[l--];
	int m=sizeSegment[l];
	while(m&&skipped<B[i]&&A[I[l][m-1]]<A[i])m--,skipped++;
	I[l].insert(I[l].begin()+m,i);
	maxSegment[l]=max(maxSegment[l],A[i]);
	sizeSegment[l]++;
	while(I[l].size()>C<<1){
		if(I.size()==l+1){
			vector<int> v;
			I.push_back(v);
			maxSegment.push_back(0);
			sizeSegment.push_back(0);
		}
		I[l+1].insert(I[l+1].begin(),I[l].begin()+C,I[l].end());
		I[l].resize(C);
		sizeSegment[l]=C;
		maxSegment[l]=A[I[l][0]];
		for(int j=1;j<sizeSegment[l];j++){
			maxSegment[l]=max(maxSegment[l],A[I[l][j]]);
		}
		l++;
	}
	sizeSegment[l]=I[l].size();
	maxSegment[l]=A[I[l][0]];
	for(int j=1;j<sizeSegment[l];j++){
		maxSegment[l]=max(maxSegment[l],A[I[l][j]]);
	}
}
int main()
{
	int N;
	scanf("%d\n",&N);
	for(int x=0;x<N;x++)
	{
		scanf("%d%d",&A[x],&B[x]);
		if(x==0)
		{
			vector<int> v;v.push_back(0),I.push_back(v);
			maxSegment.push_back(A[x]);
			sizeSegment.push_back(1);
		}
		else insert_back(x);
	}
	print();
}