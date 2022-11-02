{$r-,q-,s-,i-,o+}
const
  base=1000000007;
  maxn=111;

var
  first,nn,n,i,j,res:longint;
  c:array[0..1111,0..1111]of longint;
  kol:array[0..50]of longint;
  f:array[0..111,0..10,0..10]of longint;

  procedure rec(n,first,t:longint);
    var
      res,kt,k:longint;
      
    begin
      if (f[n][first][t]<>-1)then exit;
      if (t>9)then begin
        f[n][first][t]:=ord(n=0);
        exit;
      end;
      kt:=kol[t]-ord(t=first);
      if (kt<0)then kt:=0;
      res:=0;
      for k:=kt to n do begin
        rec(n-k,first,t+1);
        res:=(int64(f[n-k][first][t+1])*c[n][k]+res)mod base;
      end;
      f[n][first][t]:=res;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  for i:=0 to maxn do 
    for j:=0 to maxn do 
      if (j>i)then c[i][j]:=0 else
      if (j=i)or(j=0)then c[i][j]:=1 else 
      c[i][j]:=(c[i-1][j]+c[i-1][j-1])mod base;
  read(nn);
  for i:=0 to 9 do read(kol[i]);
  fillchar(f,sizeof(f),$FF);
  res:=0;
  for n:=1 to nn do begin
    for first:=1 to 9 do begin
      rec(n-1,first,0);
      res:=(res+f[n-1][first][0])mod base;
    end;
  end;
  writeln(res);
end.