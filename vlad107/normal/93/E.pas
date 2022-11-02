{$r-,q-,s-,i-,o+}
const
  maxn=300001;
var
  n,i,j,tmp:longint;
  a:array[0..500]of longint;
  f:array[0..101,0..1,0..maxn]of longint;
  xx,res,x:int64;
  procedure rec(i,j:longint;x:int64);
    var
      tx:longint;
    begin  
      if (x=0)then exit;
      if (i>n)then begin 
        if (x=xx)and(j=0)then exit;
        if (j=1)then res:=res-x else res:=res+x;
        if (x<maxn)then begin
          tx:=longint(x);
          if (j=1)then f[i][j][tx]:=-x else f[i][j][tx]:=x;
        end;
        exit;
      end;
      if (x<maxn)then begin
        tx:=longint(x);
        if (f[i][j][tx]<>0)then begin
          res:=res+f[i][j][tx];
          exit;
        end;
        rec(i+1,j,tx);
        rec(i+1,1-j,tx div a[i]);
        f[i][j][tx]:=f[i+1][j][tx]+f[i+1][1-j][tx div a[i]];
        exit;
      end;
      rec(i+1,j,x);
      rec(i+1,1-j,x div a[i]);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(x,n);
  xx:=x;
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do  
    for j:=1 to n-1 do 
      if (a[j]<a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  res:=x;
  fillchar(f,sizeof(f),$0);
  rec(1,0,x);    
  writeln(res);
  close(output);close(input);
end.