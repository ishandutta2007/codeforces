#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

int n,b;
vvi a(10,vi(10,0));
vector<vvi> mul(10, vvi(10,vi(10,0)));

void mult(int k) {
    mul[k][0][0]=mul[k-1][0][0];
    mul[k][0][1]=mul[k-1][0][1];
    mul[k][0][2]=mul[k-1][0][2];
    mul[k][0][3]=mul[k-1][0][3];
    mul[k][0][4]=mul[k-1][0][4];
    mul[k][0][5]=mul[k-1][0][5];
    mul[k][0][6]=mul[k-1][0][6];
    mul[k][0][7]=mul[k-1][0][7];
    mul[k][0][8]=mul[k-1][0][8];
    mul[k][0][9]=mul[k-1][0][9];
    mul[k][1][0]=mul[k-1][1][0];
    mul[k][1][1]=mul[k-1][1][1];
    mul[k][1][2]=mul[k-1][1][2];
    mul[k][1][3]=mul[k-1][1][3];
    mul[k][1][4]=mul[k-1][1][4];
    mul[k][1][5]=mul[k-1][1][5];
    mul[k][1][6]=mul[k-1][1][6];
    mul[k][1][7]=mul[k-1][1][7];
    mul[k][1][8]=mul[k-1][1][8];
    mul[k][1][9]=mul[k-1][1][9];
    mul[k][2][0]=mul[k-1][2][0];
    mul[k][2][1]=mul[k-1][2][1];
    mul[k][2][2]=mul[k-1][2][2];
    mul[k][2][3]=mul[k-1][2][3];
    mul[k][2][4]=mul[k-1][2][4];
    mul[k][2][5]=mul[k-1][2][5];
    mul[k][2][6]=mul[k-1][2][6];
    mul[k][2][7]=mul[k-1][2][7];
    mul[k][2][8]=mul[k-1][2][8];
    mul[k][2][9]=mul[k-1][2][9];
    mul[k][3][0]=mul[k-1][3][0];
    mul[k][3][1]=mul[k-1][3][1];
    mul[k][3][2]=mul[k-1][3][2];
    mul[k][3][3]=mul[k-1][3][3];
    mul[k][3][4]=mul[k-1][3][4];
    mul[k][3][5]=mul[k-1][3][5];
    mul[k][3][6]=mul[k-1][3][6];
    mul[k][3][7]=mul[k-1][3][7];
    mul[k][3][8]=mul[k-1][3][8];
    mul[k][3][9]=mul[k-1][3][9];
    mul[k][4][0]=mul[k-1][4][0];
    mul[k][4][1]=mul[k-1][4][1];
    mul[k][4][2]=mul[k-1][4][2];
    mul[k][4][3]=mul[k-1][4][3];
    mul[k][4][4]=mul[k-1][4][4];
    mul[k][4][5]=mul[k-1][4][5];
    mul[k][4][6]=mul[k-1][4][6];
    mul[k][4][7]=mul[k-1][4][7];
    mul[k][4][8]=mul[k-1][4][8];
    mul[k][4][9]=mul[k-1][4][9];
    mul[k][5][0]=mul[k-1][5][0];
    mul[k][5][1]=mul[k-1][5][1];
    mul[k][5][2]=mul[k-1][5][2];
    mul[k][5][3]=mul[k-1][5][3];
    mul[k][5][4]=mul[k-1][5][4];
    mul[k][5][5]=mul[k-1][5][5];
    mul[k][5][6]=mul[k-1][5][6];
    mul[k][5][7]=mul[k-1][5][7];
    mul[k][5][8]=mul[k-1][5][8];
    mul[k][5][9]=mul[k-1][5][9];
    mul[k][6][0]=mul[k-1][6][0];
    mul[k][6][1]=mul[k-1][6][1];
    mul[k][6][2]=mul[k-1][6][2];
    mul[k][6][3]=mul[k-1][6][3];
    mul[k][6][4]=mul[k-1][6][4];
    mul[k][6][5]=mul[k-1][6][5];
    mul[k][6][6]=mul[k-1][6][6];
    mul[k][6][7]=mul[k-1][6][7];
    mul[k][6][8]=mul[k-1][6][8];
    mul[k][6][9]=mul[k-1][6][9];
    mul[k][7][0]=mul[k-1][7][0];
    mul[k][7][1]=mul[k-1][7][1];
    mul[k][7][2]=mul[k-1][7][2];
    mul[k][7][3]=mul[k-1][7][3];
    mul[k][7][4]=mul[k-1][7][4];
    mul[k][7][5]=mul[k-1][7][5];
    mul[k][7][6]=mul[k-1][7][6];
    mul[k][7][7]=mul[k-1][7][7];
    mul[k][7][8]=mul[k-1][7][8];
    mul[k][7][9]=mul[k-1][7][9];
    mul[k][8][0]=mul[k-1][8][0];
    mul[k][8][1]=mul[k-1][8][1];
    mul[k][8][2]=mul[k-1][8][2];
    mul[k][8][3]=mul[k-1][8][3];
    mul[k][8][4]=mul[k-1][8][4];
    mul[k][8][5]=mul[k-1][8][5];
    mul[k][8][6]=mul[k-1][8][6];
    mul[k][8][7]=mul[k-1][8][7];
    mul[k][8][8]=mul[k-1][8][8];
    mul[k][8][9]=mul[k-1][8][9];
    mul[k][9][0]=mul[k-1][9][0];
    mul[k][9][1]=mul[k-1][9][1];
    mul[k][9][2]=mul[k-1][9][2];
    mul[k][9][3]=mul[k-1][9][3];
    mul[k][9][4]=mul[k-1][9][4];
    mul[k][9][5]=mul[k-1][9][5];
    mul[k][9][6]=mul[k-1][9][6];
    mul[k][9][7]=mul[k-1][9][7];
    mul[k][9][8]=mul[k-1][9][8];
    mul[k][9][9]=mul[k-1][9][9];

    mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][0]+a[0][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][1]+a[1][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][2]+a[2][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][3]+a[3][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][4]+a[4][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][5]+a[5][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][6]+a[6][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][7]+a[7][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][8]+a[8][0]);mul[k][0][0]=min(mul[k][0][0],mul[k-1][0][9]+a[9][0]);
    mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][0]+a[0][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][1]+a[1][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][2]+a[2][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][3]+a[3][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][4]+a[4][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][5]+a[5][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][6]+a[6][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][7]+a[7][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][8]+a[8][1]);mul[k][0][1]=min(mul[k][0][1],mul[k-1][0][9]+a[9][1]);
    mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][0]+a[0][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][1]+a[1][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][2]+a[2][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][3]+a[3][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][4]+a[4][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][5]+a[5][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][6]+a[6][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][7]+a[7][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][8]+a[8][2]);mul[k][0][2]=min(mul[k][0][2],mul[k-1][0][9]+a[9][2]);
    mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][0]+a[0][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][1]+a[1][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][2]+a[2][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][3]+a[3][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][4]+a[4][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][5]+a[5][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][6]+a[6][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][7]+a[7][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][8]+a[8][3]);mul[k][0][3]=min(mul[k][0][3],mul[k-1][0][9]+a[9][3]);
    mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][0]+a[0][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][1]+a[1][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][2]+a[2][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][3]+a[3][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][4]+a[4][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][5]+a[5][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][6]+a[6][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][7]+a[7][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][8]+a[8][4]);mul[k][0][4]=min(mul[k][0][4],mul[k-1][0][9]+a[9][4]);
    mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][0]+a[0][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][1]+a[1][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][2]+a[2][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][3]+a[3][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][4]+a[4][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][5]+a[5][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][6]+a[6][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][7]+a[7][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][8]+a[8][5]);mul[k][0][5]=min(mul[k][0][5],mul[k-1][0][9]+a[9][5]);
    mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][0]+a[0][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][1]+a[1][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][2]+a[2][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][3]+a[3][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][4]+a[4][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][5]+a[5][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][6]+a[6][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][7]+a[7][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][8]+a[8][6]);mul[k][0][6]=min(mul[k][0][6],mul[k-1][0][9]+a[9][6]);
    mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][0]+a[0][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][1]+a[1][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][2]+a[2][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][3]+a[3][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][4]+a[4][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][5]+a[5][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][6]+a[6][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][7]+a[7][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][8]+a[8][7]);mul[k][0][7]=min(mul[k][0][7],mul[k-1][0][9]+a[9][7]);
    mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][0]+a[0][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][1]+a[1][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][2]+a[2][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][3]+a[3][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][4]+a[4][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][5]+a[5][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][6]+a[6][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][7]+a[7][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][8]+a[8][8]);mul[k][0][8]=min(mul[k][0][8],mul[k-1][0][9]+a[9][8]);
    mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][0]+a[0][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][1]+a[1][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][2]+a[2][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][3]+a[3][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][4]+a[4][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][5]+a[5][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][6]+a[6][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][7]+a[7][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][8]+a[8][9]);mul[k][0][9]=min(mul[k][0][9],mul[k-1][0][9]+a[9][9]);
    mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][0]+a[0][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][1]+a[1][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][2]+a[2][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][3]+a[3][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][4]+a[4][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][5]+a[5][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][6]+a[6][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][7]+a[7][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][8]+a[8][0]);mul[k][1][0]=min(mul[k][1][0],mul[k-1][1][9]+a[9][0]);
    mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][0]+a[0][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][1]+a[1][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][2]+a[2][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][3]+a[3][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][4]+a[4][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][5]+a[5][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][6]+a[6][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][7]+a[7][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][8]+a[8][1]);mul[k][1][1]=min(mul[k][1][1],mul[k-1][1][9]+a[9][1]);
    mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][0]+a[0][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][1]+a[1][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][2]+a[2][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][3]+a[3][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][4]+a[4][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][5]+a[5][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][6]+a[6][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][7]+a[7][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][8]+a[8][2]);mul[k][1][2]=min(mul[k][1][2],mul[k-1][1][9]+a[9][2]);
    mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][0]+a[0][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][1]+a[1][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][2]+a[2][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][3]+a[3][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][4]+a[4][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][5]+a[5][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][6]+a[6][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][7]+a[7][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][8]+a[8][3]);mul[k][1][3]=min(mul[k][1][3],mul[k-1][1][9]+a[9][3]);
    mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][0]+a[0][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][1]+a[1][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][2]+a[2][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][3]+a[3][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][4]+a[4][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][5]+a[5][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][6]+a[6][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][7]+a[7][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][8]+a[8][4]);mul[k][1][4]=min(mul[k][1][4],mul[k-1][1][9]+a[9][4]);
    mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][0]+a[0][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][1]+a[1][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][2]+a[2][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][3]+a[3][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][4]+a[4][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][5]+a[5][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][6]+a[6][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][7]+a[7][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][8]+a[8][5]);mul[k][1][5]=min(mul[k][1][5],mul[k-1][1][9]+a[9][5]);
    mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][0]+a[0][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][1]+a[1][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][2]+a[2][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][3]+a[3][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][4]+a[4][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][5]+a[5][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][6]+a[6][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][7]+a[7][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][8]+a[8][6]);mul[k][1][6]=min(mul[k][1][6],mul[k-1][1][9]+a[9][6]);
    mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][0]+a[0][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][1]+a[1][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][2]+a[2][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][3]+a[3][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][4]+a[4][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][5]+a[5][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][6]+a[6][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][7]+a[7][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][8]+a[8][7]);mul[k][1][7]=min(mul[k][1][7],mul[k-1][1][9]+a[9][7]);
    mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][0]+a[0][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][1]+a[1][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][2]+a[2][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][3]+a[3][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][4]+a[4][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][5]+a[5][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][6]+a[6][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][7]+a[7][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][8]+a[8][8]);mul[k][1][8]=min(mul[k][1][8],mul[k-1][1][9]+a[9][8]);
    mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][0]+a[0][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][1]+a[1][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][2]+a[2][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][3]+a[3][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][4]+a[4][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][5]+a[5][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][6]+a[6][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][7]+a[7][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][8]+a[8][9]);mul[k][1][9]=min(mul[k][1][9],mul[k-1][1][9]+a[9][9]);
    mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][0]+a[0][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][1]+a[1][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][2]+a[2][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][3]+a[3][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][4]+a[4][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][5]+a[5][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][6]+a[6][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][7]+a[7][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][8]+a[8][0]);mul[k][2][0]=min(mul[k][2][0],mul[k-1][2][9]+a[9][0]);
    mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][0]+a[0][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][1]+a[1][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][2]+a[2][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][3]+a[3][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][4]+a[4][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][5]+a[5][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][6]+a[6][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][7]+a[7][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][8]+a[8][1]);mul[k][2][1]=min(mul[k][2][1],mul[k-1][2][9]+a[9][1]);
    mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][0]+a[0][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][1]+a[1][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][2]+a[2][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][3]+a[3][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][4]+a[4][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][5]+a[5][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][6]+a[6][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][7]+a[7][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][8]+a[8][2]);mul[k][2][2]=min(mul[k][2][2],mul[k-1][2][9]+a[9][2]);
    mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][0]+a[0][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][1]+a[1][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][2]+a[2][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][3]+a[3][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][4]+a[4][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][5]+a[5][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][6]+a[6][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][7]+a[7][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][8]+a[8][3]);mul[k][2][3]=min(mul[k][2][3],mul[k-1][2][9]+a[9][3]);
    mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][0]+a[0][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][1]+a[1][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][2]+a[2][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][3]+a[3][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][4]+a[4][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][5]+a[5][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][6]+a[6][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][7]+a[7][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][8]+a[8][4]);mul[k][2][4]=min(mul[k][2][4],mul[k-1][2][9]+a[9][4]);
    mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][0]+a[0][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][1]+a[1][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][2]+a[2][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][3]+a[3][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][4]+a[4][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][5]+a[5][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][6]+a[6][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][7]+a[7][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][8]+a[8][5]);mul[k][2][5]=min(mul[k][2][5],mul[k-1][2][9]+a[9][5]);
    mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][0]+a[0][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][1]+a[1][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][2]+a[2][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][3]+a[3][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][4]+a[4][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][5]+a[5][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][6]+a[6][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][7]+a[7][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][8]+a[8][6]);mul[k][2][6]=min(mul[k][2][6],mul[k-1][2][9]+a[9][6]);
    mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][0]+a[0][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][1]+a[1][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][2]+a[2][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][3]+a[3][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][4]+a[4][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][5]+a[5][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][6]+a[6][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][7]+a[7][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][8]+a[8][7]);mul[k][2][7]=min(mul[k][2][7],mul[k-1][2][9]+a[9][7]);
    mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][0]+a[0][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][1]+a[1][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][2]+a[2][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][3]+a[3][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][4]+a[4][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][5]+a[5][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][6]+a[6][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][7]+a[7][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][8]+a[8][8]);mul[k][2][8]=min(mul[k][2][8],mul[k-1][2][9]+a[9][8]);
    mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][0]+a[0][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][1]+a[1][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][2]+a[2][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][3]+a[3][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][4]+a[4][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][5]+a[5][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][6]+a[6][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][7]+a[7][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][8]+a[8][9]);mul[k][2][9]=min(mul[k][2][9],mul[k-1][2][9]+a[9][9]);
    mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][0]+a[0][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][1]+a[1][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][2]+a[2][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][3]+a[3][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][4]+a[4][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][5]+a[5][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][6]+a[6][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][7]+a[7][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][8]+a[8][0]);mul[k][3][0]=min(mul[k][3][0],mul[k-1][3][9]+a[9][0]);
    mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][0]+a[0][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][1]+a[1][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][2]+a[2][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][3]+a[3][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][4]+a[4][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][5]+a[5][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][6]+a[6][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][7]+a[7][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][8]+a[8][1]);mul[k][3][1]=min(mul[k][3][1],mul[k-1][3][9]+a[9][1]);
    mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][0]+a[0][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][1]+a[1][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][2]+a[2][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][3]+a[3][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][4]+a[4][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][5]+a[5][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][6]+a[6][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][7]+a[7][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][8]+a[8][2]);mul[k][3][2]=min(mul[k][3][2],mul[k-1][3][9]+a[9][2]);
    mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][0]+a[0][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][1]+a[1][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][2]+a[2][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][3]+a[3][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][4]+a[4][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][5]+a[5][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][6]+a[6][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][7]+a[7][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][8]+a[8][3]);mul[k][3][3]=min(mul[k][3][3],mul[k-1][3][9]+a[9][3]);
    mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][0]+a[0][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][1]+a[1][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][2]+a[2][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][3]+a[3][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][4]+a[4][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][5]+a[5][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][6]+a[6][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][7]+a[7][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][8]+a[8][4]);mul[k][3][4]=min(mul[k][3][4],mul[k-1][3][9]+a[9][4]);
    mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][0]+a[0][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][1]+a[1][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][2]+a[2][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][3]+a[3][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][4]+a[4][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][5]+a[5][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][6]+a[6][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][7]+a[7][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][8]+a[8][5]);mul[k][3][5]=min(mul[k][3][5],mul[k-1][3][9]+a[9][5]);
    mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][0]+a[0][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][1]+a[1][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][2]+a[2][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][3]+a[3][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][4]+a[4][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][5]+a[5][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][6]+a[6][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][7]+a[7][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][8]+a[8][6]);mul[k][3][6]=min(mul[k][3][6],mul[k-1][3][9]+a[9][6]);
    mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][0]+a[0][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][1]+a[1][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][2]+a[2][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][3]+a[3][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][4]+a[4][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][5]+a[5][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][6]+a[6][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][7]+a[7][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][8]+a[8][7]);mul[k][3][7]=min(mul[k][3][7],mul[k-1][3][9]+a[9][7]);
    mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][0]+a[0][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][1]+a[1][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][2]+a[2][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][3]+a[3][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][4]+a[4][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][5]+a[5][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][6]+a[6][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][7]+a[7][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][8]+a[8][8]);mul[k][3][8]=min(mul[k][3][8],mul[k-1][3][9]+a[9][8]);
    mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][0]+a[0][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][1]+a[1][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][2]+a[2][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][3]+a[3][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][4]+a[4][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][5]+a[5][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][6]+a[6][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][7]+a[7][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][8]+a[8][9]);mul[k][3][9]=min(mul[k][3][9],mul[k-1][3][9]+a[9][9]);
    mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][0]+a[0][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][1]+a[1][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][2]+a[2][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][3]+a[3][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][4]+a[4][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][5]+a[5][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][6]+a[6][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][7]+a[7][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][8]+a[8][0]);mul[k][4][0]=min(mul[k][4][0],mul[k-1][4][9]+a[9][0]);
    mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][0]+a[0][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][1]+a[1][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][2]+a[2][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][3]+a[3][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][4]+a[4][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][5]+a[5][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][6]+a[6][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][7]+a[7][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][8]+a[8][1]);mul[k][4][1]=min(mul[k][4][1],mul[k-1][4][9]+a[9][1]);
    mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][0]+a[0][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][1]+a[1][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][2]+a[2][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][3]+a[3][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][4]+a[4][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][5]+a[5][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][6]+a[6][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][7]+a[7][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][8]+a[8][2]);mul[k][4][2]=min(mul[k][4][2],mul[k-1][4][9]+a[9][2]);
    mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][0]+a[0][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][1]+a[1][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][2]+a[2][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][3]+a[3][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][4]+a[4][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][5]+a[5][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][6]+a[6][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][7]+a[7][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][8]+a[8][3]);mul[k][4][3]=min(mul[k][4][3],mul[k-1][4][9]+a[9][3]);
    mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][0]+a[0][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][1]+a[1][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][2]+a[2][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][3]+a[3][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][4]+a[4][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][5]+a[5][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][6]+a[6][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][7]+a[7][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][8]+a[8][4]);mul[k][4][4]=min(mul[k][4][4],mul[k-1][4][9]+a[9][4]);
    mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][0]+a[0][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][1]+a[1][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][2]+a[2][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][3]+a[3][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][4]+a[4][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][5]+a[5][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][6]+a[6][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][7]+a[7][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][8]+a[8][5]);mul[k][4][5]=min(mul[k][4][5],mul[k-1][4][9]+a[9][5]);
    mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][0]+a[0][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][1]+a[1][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][2]+a[2][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][3]+a[3][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][4]+a[4][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][5]+a[5][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][6]+a[6][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][7]+a[7][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][8]+a[8][6]);mul[k][4][6]=min(mul[k][4][6],mul[k-1][4][9]+a[9][6]);
    mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][0]+a[0][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][1]+a[1][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][2]+a[2][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][3]+a[3][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][4]+a[4][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][5]+a[5][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][6]+a[6][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][7]+a[7][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][8]+a[8][7]);mul[k][4][7]=min(mul[k][4][7],mul[k-1][4][9]+a[9][7]);
    mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][0]+a[0][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][1]+a[1][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][2]+a[2][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][3]+a[3][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][4]+a[4][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][5]+a[5][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][6]+a[6][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][7]+a[7][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][8]+a[8][8]);mul[k][4][8]=min(mul[k][4][8],mul[k-1][4][9]+a[9][8]);
    mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][0]+a[0][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][1]+a[1][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][2]+a[2][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][3]+a[3][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][4]+a[4][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][5]+a[5][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][6]+a[6][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][7]+a[7][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][8]+a[8][9]);mul[k][4][9]=min(mul[k][4][9],mul[k-1][4][9]+a[9][9]);
    mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][0]+a[0][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][1]+a[1][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][2]+a[2][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][3]+a[3][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][4]+a[4][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][5]+a[5][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][6]+a[6][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][7]+a[7][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][8]+a[8][0]);mul[k][5][0]=min(mul[k][5][0],mul[k-1][5][9]+a[9][0]);
    mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][0]+a[0][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][1]+a[1][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][2]+a[2][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][3]+a[3][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][4]+a[4][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][5]+a[5][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][6]+a[6][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][7]+a[7][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][8]+a[8][1]);mul[k][5][1]=min(mul[k][5][1],mul[k-1][5][9]+a[9][1]);
    mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][0]+a[0][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][1]+a[1][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][2]+a[2][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][3]+a[3][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][4]+a[4][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][5]+a[5][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][6]+a[6][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][7]+a[7][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][8]+a[8][2]);mul[k][5][2]=min(mul[k][5][2],mul[k-1][5][9]+a[9][2]);
    mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][0]+a[0][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][1]+a[1][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][2]+a[2][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][3]+a[3][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][4]+a[4][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][5]+a[5][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][6]+a[6][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][7]+a[7][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][8]+a[8][3]);mul[k][5][3]=min(mul[k][5][3],mul[k-1][5][9]+a[9][3]);
    mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][0]+a[0][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][1]+a[1][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][2]+a[2][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][3]+a[3][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][4]+a[4][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][5]+a[5][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][6]+a[6][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][7]+a[7][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][8]+a[8][4]);mul[k][5][4]=min(mul[k][5][4],mul[k-1][5][9]+a[9][4]);
    mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][0]+a[0][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][1]+a[1][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][2]+a[2][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][3]+a[3][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][4]+a[4][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][5]+a[5][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][6]+a[6][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][7]+a[7][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][8]+a[8][5]);mul[k][5][5]=min(mul[k][5][5],mul[k-1][5][9]+a[9][5]);
    mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][0]+a[0][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][1]+a[1][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][2]+a[2][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][3]+a[3][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][4]+a[4][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][5]+a[5][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][6]+a[6][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][7]+a[7][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][8]+a[8][6]);mul[k][5][6]=min(mul[k][5][6],mul[k-1][5][9]+a[9][6]);
    mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][0]+a[0][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][1]+a[1][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][2]+a[2][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][3]+a[3][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][4]+a[4][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][5]+a[5][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][6]+a[6][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][7]+a[7][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][8]+a[8][7]);mul[k][5][7]=min(mul[k][5][7],mul[k-1][5][9]+a[9][7]);
    mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][0]+a[0][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][1]+a[1][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][2]+a[2][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][3]+a[3][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][4]+a[4][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][5]+a[5][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][6]+a[6][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][7]+a[7][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][8]+a[8][8]);mul[k][5][8]=min(mul[k][5][8],mul[k-1][5][9]+a[9][8]);
    mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][0]+a[0][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][1]+a[1][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][2]+a[2][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][3]+a[3][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][4]+a[4][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][5]+a[5][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][6]+a[6][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][7]+a[7][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][8]+a[8][9]);mul[k][5][9]=min(mul[k][5][9],mul[k-1][5][9]+a[9][9]);
    mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][0]+a[0][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][1]+a[1][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][2]+a[2][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][3]+a[3][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][4]+a[4][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][5]+a[5][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][6]+a[6][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][7]+a[7][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][8]+a[8][0]);mul[k][6][0]=min(mul[k][6][0],mul[k-1][6][9]+a[9][0]);
    mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][0]+a[0][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][1]+a[1][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][2]+a[2][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][3]+a[3][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][4]+a[4][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][5]+a[5][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][6]+a[6][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][7]+a[7][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][8]+a[8][1]);mul[k][6][1]=min(mul[k][6][1],mul[k-1][6][9]+a[9][1]);
    mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][0]+a[0][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][1]+a[1][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][2]+a[2][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][3]+a[3][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][4]+a[4][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][5]+a[5][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][6]+a[6][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][7]+a[7][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][8]+a[8][2]);mul[k][6][2]=min(mul[k][6][2],mul[k-1][6][9]+a[9][2]);
    mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][0]+a[0][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][1]+a[1][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][2]+a[2][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][3]+a[3][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][4]+a[4][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][5]+a[5][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][6]+a[6][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][7]+a[7][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][8]+a[8][3]);mul[k][6][3]=min(mul[k][6][3],mul[k-1][6][9]+a[9][3]);
    mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][0]+a[0][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][1]+a[1][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][2]+a[2][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][3]+a[3][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][4]+a[4][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][5]+a[5][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][6]+a[6][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][7]+a[7][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][8]+a[8][4]);mul[k][6][4]=min(mul[k][6][4],mul[k-1][6][9]+a[9][4]);
    mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][0]+a[0][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][1]+a[1][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][2]+a[2][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][3]+a[3][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][4]+a[4][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][5]+a[5][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][6]+a[6][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][7]+a[7][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][8]+a[8][5]);mul[k][6][5]=min(mul[k][6][5],mul[k-1][6][9]+a[9][5]);
    mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][0]+a[0][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][1]+a[1][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][2]+a[2][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][3]+a[3][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][4]+a[4][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][5]+a[5][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][6]+a[6][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][7]+a[7][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][8]+a[8][6]);mul[k][6][6]=min(mul[k][6][6],mul[k-1][6][9]+a[9][6]);
    mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][0]+a[0][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][1]+a[1][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][2]+a[2][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][3]+a[3][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][4]+a[4][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][5]+a[5][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][6]+a[6][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][7]+a[7][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][8]+a[8][7]);mul[k][6][7]=min(mul[k][6][7],mul[k-1][6][9]+a[9][7]);
    mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][0]+a[0][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][1]+a[1][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][2]+a[2][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][3]+a[3][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][4]+a[4][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][5]+a[5][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][6]+a[6][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][7]+a[7][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][8]+a[8][8]);mul[k][6][8]=min(mul[k][6][8],mul[k-1][6][9]+a[9][8]);
    mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][0]+a[0][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][1]+a[1][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][2]+a[2][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][3]+a[3][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][4]+a[4][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][5]+a[5][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][6]+a[6][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][7]+a[7][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][8]+a[8][9]);mul[k][6][9]=min(mul[k][6][9],mul[k-1][6][9]+a[9][9]);
    mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][0]+a[0][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][1]+a[1][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][2]+a[2][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][3]+a[3][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][4]+a[4][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][5]+a[5][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][6]+a[6][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][7]+a[7][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][8]+a[8][0]);mul[k][7][0]=min(mul[k][7][0],mul[k-1][7][9]+a[9][0]);
    mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][0]+a[0][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][1]+a[1][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][2]+a[2][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][3]+a[3][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][4]+a[4][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][5]+a[5][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][6]+a[6][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][7]+a[7][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][8]+a[8][1]);mul[k][7][1]=min(mul[k][7][1],mul[k-1][7][9]+a[9][1]);
    mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][0]+a[0][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][1]+a[1][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][2]+a[2][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][3]+a[3][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][4]+a[4][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][5]+a[5][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][6]+a[6][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][7]+a[7][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][8]+a[8][2]);mul[k][7][2]=min(mul[k][7][2],mul[k-1][7][9]+a[9][2]);
    mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][0]+a[0][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][1]+a[1][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][2]+a[2][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][3]+a[3][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][4]+a[4][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][5]+a[5][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][6]+a[6][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][7]+a[7][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][8]+a[8][3]);mul[k][7][3]=min(mul[k][7][3],mul[k-1][7][9]+a[9][3]);
    mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][0]+a[0][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][1]+a[1][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][2]+a[2][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][3]+a[3][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][4]+a[4][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][5]+a[5][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][6]+a[6][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][7]+a[7][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][8]+a[8][4]);mul[k][7][4]=min(mul[k][7][4],mul[k-1][7][9]+a[9][4]);
    mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][0]+a[0][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][1]+a[1][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][2]+a[2][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][3]+a[3][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][4]+a[4][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][5]+a[5][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][6]+a[6][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][7]+a[7][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][8]+a[8][5]);mul[k][7][5]=min(mul[k][7][5],mul[k-1][7][9]+a[9][5]);
    mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][0]+a[0][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][1]+a[1][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][2]+a[2][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][3]+a[3][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][4]+a[4][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][5]+a[5][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][6]+a[6][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][7]+a[7][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][8]+a[8][6]);mul[k][7][6]=min(mul[k][7][6],mul[k-1][7][9]+a[9][6]);
    mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][0]+a[0][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][1]+a[1][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][2]+a[2][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][3]+a[3][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][4]+a[4][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][5]+a[5][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][6]+a[6][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][7]+a[7][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][8]+a[8][7]);mul[k][7][7]=min(mul[k][7][7],mul[k-1][7][9]+a[9][7]);
    mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][0]+a[0][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][1]+a[1][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][2]+a[2][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][3]+a[3][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][4]+a[4][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][5]+a[5][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][6]+a[6][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][7]+a[7][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][8]+a[8][8]);mul[k][7][8]=min(mul[k][7][8],mul[k-1][7][9]+a[9][8]);
    mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][0]+a[0][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][1]+a[1][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][2]+a[2][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][3]+a[3][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][4]+a[4][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][5]+a[5][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][6]+a[6][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][7]+a[7][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][8]+a[8][9]);mul[k][7][9]=min(mul[k][7][9],mul[k-1][7][9]+a[9][9]);
    mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][0]+a[0][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][1]+a[1][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][2]+a[2][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][3]+a[3][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][4]+a[4][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][5]+a[5][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][6]+a[6][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][7]+a[7][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][8]+a[8][0]);mul[k][8][0]=min(mul[k][8][0],mul[k-1][8][9]+a[9][0]);
    mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][0]+a[0][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][1]+a[1][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][2]+a[2][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][3]+a[3][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][4]+a[4][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][5]+a[5][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][6]+a[6][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][7]+a[7][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][8]+a[8][1]);mul[k][8][1]=min(mul[k][8][1],mul[k-1][8][9]+a[9][1]);
    mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][0]+a[0][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][1]+a[1][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][2]+a[2][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][3]+a[3][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][4]+a[4][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][5]+a[5][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][6]+a[6][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][7]+a[7][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][8]+a[8][2]);mul[k][8][2]=min(mul[k][8][2],mul[k-1][8][9]+a[9][2]);
    mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][0]+a[0][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][1]+a[1][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][2]+a[2][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][3]+a[3][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][4]+a[4][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][5]+a[5][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][6]+a[6][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][7]+a[7][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][8]+a[8][3]);mul[k][8][3]=min(mul[k][8][3],mul[k-1][8][9]+a[9][3]);
    mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][0]+a[0][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][1]+a[1][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][2]+a[2][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][3]+a[3][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][4]+a[4][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][5]+a[5][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][6]+a[6][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][7]+a[7][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][8]+a[8][4]);mul[k][8][4]=min(mul[k][8][4],mul[k-1][8][9]+a[9][4]);
    mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][0]+a[0][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][1]+a[1][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][2]+a[2][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][3]+a[3][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][4]+a[4][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][5]+a[5][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][6]+a[6][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][7]+a[7][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][8]+a[8][5]);mul[k][8][5]=min(mul[k][8][5],mul[k-1][8][9]+a[9][5]);
    mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][0]+a[0][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][1]+a[1][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][2]+a[2][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][3]+a[3][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][4]+a[4][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][5]+a[5][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][6]+a[6][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][7]+a[7][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][8]+a[8][6]);mul[k][8][6]=min(mul[k][8][6],mul[k-1][8][9]+a[9][6]);
    mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][0]+a[0][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][1]+a[1][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][2]+a[2][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][3]+a[3][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][4]+a[4][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][5]+a[5][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][6]+a[6][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][7]+a[7][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][8]+a[8][7]);mul[k][8][7]=min(mul[k][8][7],mul[k-1][8][9]+a[9][7]);
    mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][0]+a[0][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][1]+a[1][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][2]+a[2][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][3]+a[3][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][4]+a[4][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][5]+a[5][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][6]+a[6][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][7]+a[7][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][8]+a[8][8]);mul[k][8][8]=min(mul[k][8][8],mul[k-1][8][9]+a[9][8]);
    mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][0]+a[0][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][1]+a[1][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][2]+a[2][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][3]+a[3][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][4]+a[4][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][5]+a[5][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][6]+a[6][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][7]+a[7][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][8]+a[8][9]);mul[k][8][9]=min(mul[k][8][9],mul[k-1][8][9]+a[9][9]);
    mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][0]+a[0][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][1]+a[1][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][2]+a[2][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][3]+a[3][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][4]+a[4][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][5]+a[5][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][6]+a[6][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][7]+a[7][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][8]+a[8][0]);mul[k][9][0]=min(mul[k][9][0],mul[k-1][9][9]+a[9][0]);
    mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][0]+a[0][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][1]+a[1][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][2]+a[2][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][3]+a[3][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][4]+a[4][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][5]+a[5][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][6]+a[6][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][7]+a[7][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][8]+a[8][1]);mul[k][9][1]=min(mul[k][9][1],mul[k-1][9][9]+a[9][1]);
    mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][0]+a[0][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][1]+a[1][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][2]+a[2][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][3]+a[3][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][4]+a[4][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][5]+a[5][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][6]+a[6][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][7]+a[7][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][8]+a[8][2]);mul[k][9][2]=min(mul[k][9][2],mul[k-1][9][9]+a[9][2]);
    mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][0]+a[0][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][1]+a[1][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][2]+a[2][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][3]+a[3][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][4]+a[4][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][5]+a[5][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][6]+a[6][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][7]+a[7][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][8]+a[8][3]);mul[k][9][3]=min(mul[k][9][3],mul[k-1][9][9]+a[9][3]);
    mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][0]+a[0][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][1]+a[1][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][2]+a[2][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][3]+a[3][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][4]+a[4][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][5]+a[5][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][6]+a[6][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][7]+a[7][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][8]+a[8][4]);mul[k][9][4]=min(mul[k][9][4],mul[k-1][9][9]+a[9][4]);
    mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][0]+a[0][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][1]+a[1][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][2]+a[2][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][3]+a[3][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][4]+a[4][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][5]+a[5][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][6]+a[6][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][7]+a[7][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][8]+a[8][5]);mul[k][9][5]=min(mul[k][9][5],mul[k-1][9][9]+a[9][5]);
    mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][0]+a[0][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][1]+a[1][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][2]+a[2][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][3]+a[3][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][4]+a[4][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][5]+a[5][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][6]+a[6][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][7]+a[7][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][8]+a[8][6]);mul[k][9][6]=min(mul[k][9][6],mul[k-1][9][9]+a[9][6]);
    mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][0]+a[0][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][1]+a[1][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][2]+a[2][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][3]+a[3][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][4]+a[4][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][5]+a[5][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][6]+a[6][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][7]+a[7][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][8]+a[8][7]);mul[k][9][7]=min(mul[k][9][7],mul[k-1][9][9]+a[9][7]);
    mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][0]+a[0][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][1]+a[1][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][2]+a[2][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][3]+a[3][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][4]+a[4][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][5]+a[5][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][6]+a[6][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][7]+a[7][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][8]+a[8][8]);mul[k][9][8]=min(mul[k][9][8],mul[k-1][9][9]+a[9][8]);
    mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][0]+a[0][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][1]+a[1][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][2]+a[2][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][3]+a[3][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][4]+a[4][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][5]+a[5][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][6]+a[6][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][7]+a[7][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][8]+a[8][9]);mul[k][9][9]=min(mul[k][9][9],mul[k-1][9][9]+a[9][9]);
    
    
}

int test() {
    int u = 0;
    u=max(u, mul[9][0][0]*((0<n)&(0<n)));
    u=max(u, mul[9][0][1]*((0<n)&(1<n)));
    u=max(u, mul[9][0][2]*((0<n)&(2<n)));
    u=max(u, mul[9][0][3]*((0<n)&(3<n)));
    u=max(u, mul[9][0][4]*((0<n)&(4<n)));
    u=max(u, mul[9][0][5]*((0<n)&(5<n)));
    u=max(u, mul[9][0][6]*((0<n)&(6<n)));
    u=max(u, mul[9][0][7]*((0<n)&(7<n)));
    u=max(u, mul[9][0][8]*((0<n)&(8<n)));
    u=max(u, mul[9][0][9]*((0<n)&(9<n)));
    u=max(u, mul[9][1][0]*((1<n)&(0<n)));
    u=max(u, mul[9][1][1]*((1<n)&(1<n)));
    u=max(u, mul[9][1][2]*((1<n)&(2<n)));
    u=max(u, mul[9][1][3]*((1<n)&(3<n)));
    u=max(u, mul[9][1][4]*((1<n)&(4<n)));
    u=max(u, mul[9][1][5]*((1<n)&(5<n)));
    u=max(u, mul[9][1][6]*((1<n)&(6<n)));
    u=max(u, mul[9][1][7]*((1<n)&(7<n)));
    u=max(u, mul[9][1][8]*((1<n)&(8<n)));
    u=max(u, mul[9][1][9]*((1<n)&(9<n)));
    u=max(u, mul[9][2][0]*((2<n)&(0<n)));
    u=max(u, mul[9][2][1]*((2<n)&(1<n)));
    u=max(u, mul[9][2][2]*((2<n)&(2<n)));
    u=max(u, mul[9][2][3]*((2<n)&(3<n)));
    u=max(u, mul[9][2][4]*((2<n)&(4<n)));
    u=max(u, mul[9][2][5]*((2<n)&(5<n)));
    u=max(u, mul[9][2][6]*((2<n)&(6<n)));
    u=max(u, mul[9][2][7]*((2<n)&(7<n)));
    u=max(u, mul[9][2][8]*((2<n)&(8<n)));
    u=max(u, mul[9][2][9]*((2<n)&(9<n)));
    u=max(u, mul[9][3][0]*((3<n)&(0<n)));
    u=max(u, mul[9][3][1]*((3<n)&(1<n)));
    u=max(u, mul[9][3][2]*((3<n)&(2<n)));
    u=max(u, mul[9][3][3]*((3<n)&(3<n)));
    u=max(u, mul[9][3][4]*((3<n)&(4<n)));
    u=max(u, mul[9][3][5]*((3<n)&(5<n)));
    u=max(u, mul[9][3][6]*((3<n)&(6<n)));
    u=max(u, mul[9][3][7]*((3<n)&(7<n)));
    u=max(u, mul[9][3][8]*((3<n)&(8<n)));
    u=max(u, mul[9][3][9]*((3<n)&(9<n)));
    u=max(u, mul[9][4][0]*((4<n)&(0<n)));
    u=max(u, mul[9][4][1]*((4<n)&(1<n)));
    u=max(u, mul[9][4][2]*((4<n)&(2<n)));
    u=max(u, mul[9][4][3]*((4<n)&(3<n)));
    u=max(u, mul[9][4][4]*((4<n)&(4<n)));
    u=max(u, mul[9][4][5]*((4<n)&(5<n)));
    u=max(u, mul[9][4][6]*((4<n)&(6<n)));
    u=max(u, mul[9][4][7]*((4<n)&(7<n)));
    u=max(u, mul[9][4][8]*((4<n)&(8<n)));
    u=max(u, mul[9][4][9]*((4<n)&(9<n)));
    u=max(u, mul[9][5][0]*((5<n)&(0<n)));
    u=max(u, mul[9][5][1]*((5<n)&(1<n)));
    u=max(u, mul[9][5][2]*((5<n)&(2<n)));
    u=max(u, mul[9][5][3]*((5<n)&(3<n)));
    u=max(u, mul[9][5][4]*((5<n)&(4<n)));
    u=max(u, mul[9][5][5]*((5<n)&(5<n)));
    u=max(u, mul[9][5][6]*((5<n)&(6<n)));
    u=max(u, mul[9][5][7]*((5<n)&(7<n)));
    u=max(u, mul[9][5][8]*((5<n)&(8<n)));
    u=max(u, mul[9][5][9]*((5<n)&(9<n)));
    u=max(u, mul[9][6][0]*((6<n)&(0<n)));
    u=max(u, mul[9][6][1]*((6<n)&(1<n)));
    u=max(u, mul[9][6][2]*((6<n)&(2<n)));
    u=max(u, mul[9][6][3]*((6<n)&(3<n)));
    u=max(u, mul[9][6][4]*((6<n)&(4<n)));
    u=max(u, mul[9][6][5]*((6<n)&(5<n)));
    u=max(u, mul[9][6][6]*((6<n)&(6<n)));
    u=max(u, mul[9][6][7]*((6<n)&(7<n)));
    u=max(u, mul[9][6][8]*((6<n)&(8<n)));
    u=max(u, mul[9][6][9]*((6<n)&(9<n)));
    u=max(u, mul[9][7][0]*((7<n)&(0<n)));
    u=max(u, mul[9][7][1]*((7<n)&(1<n)));
    u=max(u, mul[9][7][2]*((7<n)&(2<n)));
    u=max(u, mul[9][7][3]*((7<n)&(3<n)));
    u=max(u, mul[9][7][4]*((7<n)&(4<n)));
    u=max(u, mul[9][7][5]*((7<n)&(5<n)));
    u=max(u, mul[9][7][6]*((7<n)&(6<n)));
    u=max(u, mul[9][7][7]*((7<n)&(7<n)));
    u=max(u, mul[9][7][8]*((7<n)&(8<n)));
    u=max(u, mul[9][7][9]*((7<n)&(9<n)));
    u=max(u, mul[9][8][0]*((8<n)&(0<n)));
    u=max(u, mul[9][8][1]*((8<n)&(1<n)));
    u=max(u, mul[9][8][2]*((8<n)&(2<n)));
    u=max(u, mul[9][8][3]*((8<n)&(3<n)));
    u=max(u, mul[9][8][4]*((8<n)&(4<n)));
    u=max(u, mul[9][8][5]*((8<n)&(5<n)));
    u=max(u, mul[9][8][6]*((8<n)&(6<n)));
    u=max(u, mul[9][8][7]*((8<n)&(7<n)));
    u=max(u, mul[9][8][8]*((8<n)&(8<n)));
    u=max(u, mul[9][8][9]*((8<n)&(9<n)));
    u=max(u, mul[9][9][0]*((9<n)&(0<n)));
    u=max(u, mul[9][9][1]*((9<n)&(1<n)));
    u=max(u, mul[9][9][2]*((9<n)&(2<n)));
    u=max(u, mul[9][9][3]*((9<n)&(3<n)));
    u=max(u, mul[9][9][4]*((9<n)&(4<n)));
    u=max(u, mul[9][9][5]*((9<n)&(5<n)));
    u=max(u, mul[9][9][6]*((9<n)&(6<n)));
    u=max(u, mul[9][9][7]*((9<n)&(7<n)));
    u=max(u, mul[9][9][8]*((9<n)&(8<n)));
    u=max(u, mul[9][9][9]*((9<n)&(9<n)));
    return u;
}
bool fo(int i, int j) {
    cin>>a[i][j];
    return true;
}
void k(int i, int j) {
    ((i<n) && (j<n))?  (fo(i,j)) : (a[i][j]=10000);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    ll ans=0;
    cin>>n;
    k(0,0);k(0,1);k(0,2);k(0,3);k(0,4);k(0,5);k(0,6);k(0,7);k(0,8);k(0,9);k(1,0);k(1,1);k(1,2);k(1,3);k(1,4);k(1,5);k(1,6);k(1,7);k(1,8);k(1,9);k(2,0);k(2,1);k(2,2);k(2,3);k(2,4);k(2,5);k(2,6);k(2,7);k(2,8);k(2,9);k(3,0);k(3,1);k(3,2);k(3,3);k(3,4);k(3,5);k(3,6);k(3,7);k(3,8);k(3,9);k(4,0);k(4,1);k(4,2);k(4,3);k(4,4);k(4,5);k(4,6);k(4,7);k(4,8);k(4,9);k(5,0);k(5,1);k(5,2);k(5,3);k(5,4);k(5,5);k(5,6);k(5,7);k(5,8);k(5,9);k(6,0);k(6,1);k(6,2);k(6,3);k(6,4);k(6,5);k(6,6);k(6,7);k(6,8);k(6,9);k(7,0);k(7,1);k(7,2);k(7,3);k(7,4);k(7,5);k(7,6);k(7,7);k(7,8);k(7,9);k(8,0);k(8,1);k(8,2);k(8,3);k(8,4);k(8,5);k(8,6);k(8,7);k(8,8);k(8,9);k(9,0);k(9,1);k(9,2);k(9,3);k(9,4);k(9,5);k(9,6);k(9,7);k(9,8);k(9,9);
    mul[0] = a;
    //cout<<mul[0].size()<<endl;
    mult(1);mult(2);mult(3);mult(4);mult(5);mult(6);mult(7);mult(8);mult(9);
    
    cout<<test();
    
    // cout<<ans;
}