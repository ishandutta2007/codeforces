#include<iostream>

using namespace std;

char sa[55][55], sb[55][55];

int main()
{
  int na, ma, nb, mb;

  while(cin >> na >> ma) {
    for(int i=0; i<na; ++i) {
      cin >> sa[i];

      for(int j=0; j<ma; ++j) {
        sa[i][j] -= '0';
      }
    }

    cin >> nb >> mb;
    for(int i=0; i<nb; ++i) {
      cin >> sb[i];

      for(int j=0; j<mb; ++j) {
        sb[i][j] -= '0';
      }
    }

    int maxv = -1, maxx = -1, maxy = -1;
    for(int x=-50; x<=50; ++x) {
      for(int y=-50; y<=50; ++y) {
        int v = 0;
        
        for(int i=0; i<na; ++i) {
          int ii = i+x;
          if(ii < 0 || ii >= nb) continue;

          for(int j=0; j<ma; ++j) {
            int jj = j+y;
            if(jj < 0 || jj >= mb) continue;

            v += sa[i][j]*sb[ii][jj];
          }
        }

        if(maxv < v) {
          maxv = v;
          maxx = x;
          maxy = y;
        }
      }
    }

    cout << maxx << " " << maxy << endl;
  }
}