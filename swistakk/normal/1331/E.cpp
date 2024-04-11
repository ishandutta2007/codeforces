#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

int size;
// unsigned char* readBMP(char* filename)
// {
//   int i;
//   FILE* f = fopen(filename, "rb");
//   unsigned char info[54];
//   fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
//   
//   // extract image height and width from header
//   int width = *(int*)&info[18];
//   int height = *(int*)&info[22];
//   
//   size = 3 * width * height;
//   debug(width, height, size);
//   unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
//   fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
//   fclose(f);
//   
//   for(i = 0; i < size; i += 3)
//   {
//     unsigned char tmp = data[i];
//     data[i] = data[i+2];
//     data[i+2] = tmp;
//   }
//   
//   return data;
// }
int width, height;
int ret[1000][1000];
void ReadBMP(char* filename)
{
  int i;
  FILE* f = fopen(filename, "rb");
  
  if(f == NULL)
    throw "Argument Exception";
  
  unsigned char info[54];
  fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
  
  // extract image height and width from header
  width = *(int*)&info[18];
  height = *(int*)&info[22];
  
  cout << endl;
  cout << "  Name: " << filename << endl;
  cout << " Width: " << width << endl;
  cout << "Height: " << height << endl;
  
  int row_padded = (width*3 + 3) & (~3);
  unsigned char* data = new unsigned char[row_padded];
  unsigned char tmp;
  
  for(int i = 0; i < height; i++)
  {
    fread(data, sizeof(unsigned char), row_padded, f);
    for(int j = 0; j < width*3; j += 3)
    {
      // Convert (B, G, R) to (R, G, B)
      tmp = data[j];
      data[j] = data[j+2];
      data[j+2] = tmp;
      ret[i][j / 3] = (int)data[j] + (int)data[j + 1] + (int)data[j + 2];
//       if (rand() % 100 == 0) {
//         debug((int)data[j], (int)data[j + 1], (int)data[j + 2]);
//       }
      //cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
    }
  }
  
  fclose(f);
  //return data;
}

string row[64];


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  row[0] = "#.##########################.#.#......#.########################";
  row[1] = "#.######################.#...#.#.#.##.#.....####################";
  row[2] = "#.####################...#.###.###..#.####.##.##################";
  row[3] = "#.#################....#.#.#.....####....#.#...#.###############";
  row[4] = "#.################..######.#.#####....####.#.#.#..##############";
  row[5] = "#.##############.##..#.....#...#...#.##.#..###.##.#.############";
  row[6] = "#.#############...##.##.######.#.###....##..#..#..#..###########";
  row[7] = "#.###########......#..#..#...#...#...####..##.##.###...#########";
  row[8] = "#.##########............####.#####.###.#..##..#..#.##...########";
  row[9] = "#.#########....................#.......##....##..........#######";
  row[10] = "#.########................................................######";
  row[11] = "#.#######..................................................#####";
  row[12] = "#.#######..................................................#####";
  row[13] = "#.######....................................................####";
  row[14] = "#.#####......................................................###";
  row[15] = "#.#####......................................................###";
  row[16] = "#.####........................................................##";
  row[17] = "#.###..........................................................#";
  row[18] = "#.#####........................................................#";
  row[19] = "#.#######............###.##..............###.#.#.............###";
  row[20] = "#.##..#####.........##.###...............#.#######........######";
  row[21] = "#.##....#####.....###..#.###...............#..#..##.#..#######..";
  row[22] = "..#.......#####.###...##...##...........#.##.###..#########.....";
  row[23] = "..#.........#####.##.##..#..###.........#..#.....##.####........";
  row[24] = "..#............#..#...#####...##.......###.##.####...#..........";
  row[25] = "..#.........#####.###...#...###........#.#.....#.###.##.#.......";
  row[26] = ".#............#...#.##.##.###.##......##.##.####..#...###.......";
  row[27] = ".#...........###.##.#..#...#...#....#.#...#....##...###.#.......";
  row[28] = ".#...........#......#....####.##.#.####.#.##.#....###...#.......";
  row[29] = ".#...........#####.##.##...#...###.#.#..#..#.##.###.##.##.......";
  row[30] = ".#............#..#....#..#...###.#...#####....#.#......#........";
  row[31] = ".#...........###...##.##.###...#.##...#....##.#...###.###.......";
  row[32] = ".#.............#####..#...#..#...#..#####.##..#..##.###.#.......";
  row[33] = ".#..............#..#.####.#.####.#.##.#.#..#.###..#..#..........";
  row[34] = ".#............####....#.#.#.#.#....#..#.##.#...##...###.........";
  row[35] = ".#.............#.##.###...###....###.##..####.##..###...........";
  row[36] = ".#................###...###.#..#..#..#..##.#...#.##.##..........";
  row[37] = ".#..................###.#......#####.......###.###..............";
  row[38] = "..#................##.####.....#.#...........###.##.............";
  row[39] = "..#..............................####...........................";
  row[40] = "..#...........................#.##.#............................";
  row[41] = "..#.........................#.###...............................";
  row[42] = "#.##........................###.###.............................";
  row[43] = "#.##.......##...................#...............................";
  row[44] = "#.###.......#.#................###.....................#.......#";
  row[45] = "#.###.......###.###...........##.#...........#.....#.####......#";
  row[46] = "#.###.......#.#.#.##.#.###..#.#..##.#.##.#..###..#####.#.......#";
  row[47] = "#.####........###..#####.#######..###..######.#.##...#........##";
  row[48] = "#.#####.......#.##....#....#...##...####...#.....#.#.........###";
  row[49] = "#.#####..........#.##.##.###.#....#...#..#.#####.###.........###";
  row[50] = "#.######........####..#..#.####.###.#.####...#.###..........####";
  row[51] = "#.#######.........#..###.....#..#.#.###.#..###.............#####";
  row[52] = "#.#######.........##...##.#.###...###.#...##.###...........#####";
  row[53] = "#.########.........###....###...#..#....#....#............######";
  row[54] = "#.#########.........#..####.#.######.####.#..............#######";
  row[55] = "#.##########............#.#....#..#..#.#..##............########";
  row[56] = "#.###########.............####....####.####............#########";
  row[57] = "#.#############....................#.................###########";
  row[58] = "#.##############....................................############";
  row[59] = "#.################................................##############";
  row[60] = "#.#################..............................###############";
  row[61] = "#.####################........................##################";
  row[62] = "#.######################....................####################";
  row[63] = "#.##########################............########################";
  
//   char heh[20];
//   //sprintf(heh, "purple.bmp");
//   sprintf(heh, "smiley.bmp");
//   ReadBMP(heh);
//   debug(size);
//   REP (i, height) {
//     REP (j, width) {
//       
//       if (ret[i][j] == 0) {
//         cerr<<"#";
//       } else {
//         cerr<<".";
//       }
//     }
//     cerr<<endl;
//   }
//   REP (i, 64) {
//     cout<<"row["<<i<<"] = \"";
//     REP (j, 64) {
//       
//       int a = 15 * (63 - i) + 8;
//       int b = 15 * j + 8;
//       int cnt = 0;
//       REP (k, a) {
//         cnt += (ret[k][b] == 0);
//       }
//       if (cnt % 2 == 0) {
//         cout<<"#";
//       } else {
//         cout<<".";
//       }
//     }
//     cout<<"\";"<<endl;
//   }
      
  int a, b;
  cin>>a>>b;
  if (b <= 61) {
    if (row[a][b + 2] == '#') {
      cout<<"OUT\n";
    } else {
      cout<<"IN\n";
    }
  } else if (b == 62) {
    if (a >= 22 && a <= 41) {
      cout<<"IN\n";
    } else {
      cout<<"OUT\n";
    }
  } else {
    if (a >= 26 && a <= 37) {
      cout<<"IN\n";
    } else {
      cout<<"OUT\n";
    }
  }
      
  
//   int a, b;
//   cin>>a>>b;
//   a = 63 - a;
//   a = 15 * a + 8;
//   b = 15 * b + 8;
//   int cnt = 0;
//   REP (i, a) {
//     cnt += (ret[i][b] == 0);
//   }
//   if (cnt % 2 == 1) {
//     cout<<"IN\n";
//   } else {
//     cout<<"OUT\n";
//   }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}