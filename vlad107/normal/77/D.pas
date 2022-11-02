{$r-,q-,s-,i-,o+}
const
  base=1000000007;
type
  tstring=ansistring;
var
  kol,n,m,i,j,x,y,ci:longint;
  s:array[1..4]of tstring;
  g:array[0..1111,0..1111]of longint;
  t:array[0..1111,0..5]of longint;
  f,f1,f2:array[0..1111]of longint;
  procedure solve;
    var
      i:longint;
    begin
      fillchar(t,sizeof(t),$0);
      if (n=1)then begin
        f2[j]:=ord((g[1][j]<>1)and(g[1][j+1]<>1));
        exit;
      end;
      t[1][0]:=1;
      for i:=1 to n-1 do begin
        if (g[i][j]<>1)and(g[i][j+1]<>1)then t[i+1][0]:=(t[i+1][0]+t[i][0])mod base;
        if (g[i][j]<>2)and(g[i+1][j]<>2)then t[i+1][2]:=(t[i+1][2]+t[i][0])mod base;
        if (g[i][j+1]<>2)and(g[i+1][j+1]<>2)then t[i+1][1]:=(t[i+1][1]+t[i][0])mod base;
        if (g[i][j]<>2)and(g[i][j+1]<>2)and(g[i+1][j]<>2)and(g[i+1][j+1]<>2)then t[i+1][3]:=(t[i+1][3]+t[i][0])mod base;

        if (g[i][j]<>2)and(g[i+1][j]<>2)then t[i+1][2]:=(t[i+1][2]+t[i][1])mod base;

        if (g[i][j+1]<>2)and(g[i+1][j+1]<>2)then t[i+1][1]:=(t[i+1][1]+t[i][1])mod base;

        t[i+1][0]:=(t[i+1][0]+t[i][3])mod base;
      end;
      f2[j]:=t[n][3]+t[n][0]*ord((g[n][j]<>1)and(g[n][j+1]<>1));
    end;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(n,m);
  for i:=1 to n do begin
    readln(s[1]);
    readln(s[1]);
    readln(s[2]);
    readln(s[3]);
    ci:=0;
    j:=2;
    while (j+2<=length(s[1]))do begin
      inc(ci);
      kol:=0;
      for x:=0 to 2 do
        for y:=0 to 2 do
          if (s[x+1][y+j]='O')then inc(kol);
      if (kol<2)or(kol=4)or(kol=5)then begin
        g[i][ci]:=3;
        inc(j,4);
        continue;
      end;
      if (kol=6)then begin
        if (s[2][j]='O')then g[i][ci]:=1 else g[i][ci]:=2;
        inc(j,4);
        continue;
      end;
      if (s[3][j+2]='.')then g[i][ci]:=1 else g[i][ci]:=2;
      inc(j,4);
    end;
  end;
  readln(s[1]);
  fillchar(f1,sizeof(f1),$0);
  fillchar(f2,sizeof(f2),$0);
  for j:=1 to m do begin
    if (n and 1=1)then begin
      f1[j]:=0;
      continue;
    end;
    f1[j]:=1;
    for i:=1 to n do
      if (g[i][j]and 1=0)then begin
        f1[j]:=0;
        break;
      end;
  end;
  for j:=1 to m-1 do solve;
  fillchar(f,sizeof(f),$0);
  f[1]:=1;
  for j:=1 to m do begin
    if (j<=m)then f[j+1]:=(f[j+1]+f[j]*f1[j])mod base;
    if (j+1<=m)then f[j+2]:=(f[j+2]+int64(f[j])*f2[j]-f[j]*f1[j]*f1[j+1])mod base;
  end;
  writeln(f[m+1]);
end.