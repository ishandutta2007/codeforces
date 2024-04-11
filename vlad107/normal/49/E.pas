{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  f:array[0..111,0..111]of longint;
  f1,f2:array[0..111,0..111,'a'..'z']of boolean;
  a,b,c:array[0..111]of char;
  s1,s2:string;
  n,ni,nj,d1,d2,i,j,q,t:longint;
  ch:char;

begin
  readln(s1);
  readln(s2);
  readln(n);
  for i:=1 to n do readln(a[i],b[i],b[i],b[i],c[i]);
  d1:=length(s1);
  d2:=length(s2);
//1
  fillchar(f1,sizeof(f1),false);
  for i:=1 to d1 do f1[i][1][s1[i]]:=true;
  for j:=2 to d1 do
    for i:=1 to d1-j+1 do
      for q:=1 to n do if (not f1[i][j][a[q]])then
        for t:=i to i+j-2 do
          if (f1[i][t-i+1][b[q]])and(f1[t+1][i+j-1-t][c[q]])
            then begin
              f1[i][j][a[q]]:=true;
              break;
            end;
//2
  fillchar(f2,sizeof(f2),false);
  for i:=1 to d2 do f2[i][1][s2[i]]:=true;
  for j:=2 to d2 do
    for i:=1 to d2-j+1 do
      for q:=1 to n do if (not f2[i][j][a[q]])then
        for t:=i to i+j-2 do
          if (f2[i][t-i+1][b[q]])and(f2[t+1][i+j-1-t][c[q]])
            then begin
              f2[i][j][a[q]]:=true;
              break;
            end;
  for i:=1 to d1+1 do
    for j:=1 to d2+1 do
      f[i][j]:=inf;
  f[1][1]:=0;
  for i:=1 to d1 do
    for j:=1 to d2 do if (f[i][j]<>inf)then
      for ch:='a'to 'z' do
        for ni:=i to d1 do
          if (f1[i][ni-i+1][ch])then
            for nj:=j to d2 do
              if (f2[j][nj-j+1][ch])and(f[i][j]+1<f[ni+1][nj+1])
                then f[ni+1][nj+1]:=f[i][j]+1;
  if (f[d1+1][d2+1]=inf)
    then writeln(-1)
    else writeln(f[d1+1][d2+1]);
end.