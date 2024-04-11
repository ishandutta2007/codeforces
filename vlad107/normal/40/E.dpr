{$r-,q-,s-,i-,o+}
var
  q,base,i,j,n,m,k,tmp,x,y,z,res:longint;
  first,swap:boolean;
  a:array[0..1111,0..1111]of longint;
  f:array[0..1111,0..1]of longint;
  used:array[0..1111]of boolean;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m,k);
  if (k>=n)then begin
    tmp:=n;n:=m;m:=tmp;
    swap:=true;
  end else swap:=false;
  fillchar(a,sizeof(a),$0);
  fillchar(used,sizeof(used),false);
  for i:=1 to k do begin
    read(x,y,z);
    if (swap)then begin 
      a[y][x]:=z;
      used[y]:=true;
    end else begin
      a[x][y]:=z;
      used[x]:=true;
    end;
  end;
  read(base);
  first:=true;
  res:=1;
  for i:=1 to n do begin 
    if (first)and(not used[i])then begin
      first:=false;
      continue;
    end;
    f[0][0]:=1;
    f[0][1]:=0;
    for j:=1 to m do 
      for q:=0 to 1 do 
        if (a[i][j]=1)then f[j][q]:=f[j-1][q] else
        if (a[i][j]=-1)then f[j][q]:=f[j-1][1-q] else
        f[j][q]:=(f[j-1][0]+f[j-1][1])mod base;
    res:=int64(res)*f[m][1] mod base;
  end;
  if (n and 1<>m and 1)then res:=0;
  writeln(res);
  close(output);close(input);
end.