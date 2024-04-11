using System;
using System.Text;
using System.Collections.Generic;

namespace HProblems {
  public class ProtectSheep {
      
    public static string ReplaceAtIndex(string text, int index, char c)
    {
        var stringBuilder = new StringBuilder(text);
        stringBuilder[index] = c;
        return stringBuilder.ToString();
    }  
      
    static int[] StringToArray(string line) {
      if (line == null) return new int[0];
      var setNumbers = new List<int>();
      foreach (var number in line.Split(' ')) setNumbers.Add(Convert.ToInt32(number));
      return setNumbers.ToArray();
    }

    static void Main() {
      int R = 6, C = 8;
      int[] oldres={-1,-1};
      int i, j, pos;
      bool noSol = false;
      int[][] sc = { new int[] { 3, 3,3,4,4,3,3,3 },
          new int[] { 3, 3,3,4,4,3,3,3 },
           new int[] { 2, 2,2,3,3,2,2,2},
           new int[] { 2, 2,2,3,3,2,2,2},
          new int[] { 1, 1,1,2,2,1,1,1},
           new int[] { 1, 1,1,2,2,1,1,1}};
      int res=0;
      string[] pasture = new string[R];
      for (i = 0; i < R; ++i) pasture[i] = Console.ReadLine();

      for (i = 0; i < R ; ++i) {
        for (j = 0; j < C; ++j) {
          if (pasture[i][j] == '.') {
              if (sc[i][j]>res) {pasture[i]=ReplaceAtIndex(pasture[i],j,'P'); 
                  if (res>0) {
                      pasture[oldres[0]]=ReplaceAtIndex(pasture[oldres[0]],oldres[1],'.');
                  }
                  oldres[0]=i;
                  oldres[1]=j;
                  res=sc[i][j];
              }
          }
        }
      }
    
    for (i=0;i<R;++i) {
        Console.WriteLine(pasture[i]);
    }

    }
  }
}