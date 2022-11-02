{$r-,q-,s-,i-,o+}
const
  hx:array[1..8]of longint=(1,0,-1,0,1,-1,-1,1);
  hy:array[1..8]of longint=(0,1,0,-1,1,1,-1,-1);
var
  qh,cx,cy,tt,res,i,j,n,m,k:longint;
  b,f3,f4,a,f1,f2:array[0..255,0..255]of longint;
  ch:char;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(tt);
  while (tt>0)do begin
    dec(tt);
    readln(n,m);
    for i:=0 to n+1 do
      for j:=0 to m+1 do begin
        f1[i][j]:=0;
        f2[i][j]:=0;
        b[i][j]:=0;
        f3[i][j]:=0;
        f4[i][j]:=0;
      end;
    res:=0;
    for i:=1 to n do begin
      for j:=1 to m do begin
        read(ch);
        a[i][j]:=ord(ch)-48;
      end;
      readln;
    end;
    for i:=1 to n do
      for j:=1 to m do
        for qh:=1 to 8 do begin
          cx:=i+hx[qh];
          cy:=j+hy[qh];
          if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
          inc(b[i][j],a[cx][cy]);
        end;
    for i:=1 to n do
      for j:=1 to m do begin
        f1[i][j]:=(f1[i][j-1]+1)*a[i][j];
        f3[i][j]:=f3[i][j-1]+b[i][j];
        f2[i][j]:=(f2[i-1][j]+1)*a[i][j];
        f4[i][j]:=f4[i-1][j]+b[i][j];
      end;
    for k:=2 to m do
      for i:=k to n do
        for j:=k to m do
          if (f1[i][j]>=k)and(f2[i][j]>=k)and(f1[i-k+1][j]>=k)and(f2[i][j-k+1]>=k)and
             (f3[i][j]-f3[i][j-k]+f4[i][j]-f4[i-k][j]+f3[i-k+1][j]-f3[i-k+1][j-k]+f4[i][j-k+1]-f4[i-k][j-k+1]=8*(k+1))then inc(res);
    for i:=0 to n+1 do
      for j:=0 to m+1 do begin
        f1[i][j]:=0;
        f2[i][j]:=0;
        f3[i][j]:=0;
        f4[i][j]:=0;
      end;
    for i:=1 to n do
      for j:=1 to m do begin
        f1[i][j]:=(f1[i-1][j-1]+1)*a[i][j];
        f3[i][j]:=f3[i-1][j-1]+b[i][j];
      end;
    for i:=1 to n do
      for j:=m downto 1 do begin
        f2[i][j]:=(f2[i-1][j+1]+1)*a[i][j];
        f4[i][j]:=f4[i-1][j+1]+b[i][j];
      end;
    for k:=2 to n do
      for i:=k to n do
        for j:=k to m-k+1 do
          if (f1[i][j]>=k)and(f2[i][j]>=k)and(f2[i-k+1][j-k+1]>=k)and(f1[i-k+1][j+k-1]>=k)and
             (f3[i][j]-f3[i-k][j-k]+f4[i][j]-f4[i-k][j+k]+f3[i-k+1][j+k-1]-f3[i-k-k+1][j-1]+f4[i-k+1][j-k+1]-f4[i-k-k+1][j+1]=8*k)then inc(res);
    writeln(res);
  end;
end.