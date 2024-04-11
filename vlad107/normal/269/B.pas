{$r-,q-,s-,i-,o+}
var
  ch:double;
  ans,cr,q,j,n,m,i:longint;
  y,x:array[0..500500]of longint;
  f:array[0..5005,0..5005]of longint;
  
  procedure qs(l,r:longint);
    var
      xx,tmp,i,j:longint;
      
    begin
      xx:=y[l+random(r-l+1)];
      i:=l;j:=r;
      while (i<=j)do begin
        while (xx>y[i])do inc(i);
        while (xx<y[j])do dec(j);
        if (i>j)then break;
        tmp:=y[i];y[i]:=y[j];y[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  read(n,m);
  for i:=1 to n do readln(x[i],ch);
  for i:=1 to n do y[i]:=x[i];
  qs(1,n);
  ans:=0;
  fillchar(f,sizeof(f),$0);
  for i:=1 to n+1 do 
    for j:=1 to n+1 do begin
      if (f[i][j]>ans)then ans:=f[i][j];
      if (i<=n)and(f[i][j]>f[i+1][j])then f[i+1][j]:=f[i][j];
      if (j<=n)and(f[i][j]>f[i][j+1])then f[i][j+1]:=f[i][j];
      if (i<=n)and(j<=n)and(x[i]=y[j])and(f[i][j]+1>f[i+1][j+1])then f[i+1][j+1]:=f[i][j]+1;
    end;
  writeln(n-f[n+1][n+1]);
end.