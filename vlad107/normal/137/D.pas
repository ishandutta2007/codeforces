const
  inf=1000000000;
var
  pf,f,g:array[0..555,0..555]of longint;
  e,res,s:ansistring;
  n,i,j,q,x,y,k:longint;

begin
  readln(s);
  readln(k);
  n:=length(s);


  for i:=1 to n do g[i][1]:=0;
  for i:=1 to n-1 do g[i][2]:=ord(s[i]<>s[i+1]);
  for j:=3 to n do 
    for i:=1 to n-j+1 do g[i][j]:=g[i+1][j-2]+ord(s[i]<>s[i+j-1]);


  for i:=1 to n+1 do 
    for j:=0 to k do f[i][j]:=inf;
  f[1][0]:=0;
  for i:=1 to n do 
    for j:=0 to k-1 do 
      if (f[i][j]<>inf)then
        for q:=1 to n-i+1 do 
          if (f[i][j]+g[i][q]<f[i+q][j+1])
            then begin
              f[i+q][j+1]:=f[i][j]+g[i][q];
              pf[i+q][j+1]:=q;
            end;
  x:=n+1;
  y:=1;
  for i:=2 to k do 
    if (f[n+1][i]<f[x][y])then y:=i;
  res:='';
  writeln(f[x][y]);
  while (x>1)do begin
    q:=pf[x][y];
    e:=copy(s,x-q,q);
    i:=1;j:=length(e);
    while (i<j)do begin
      if (e[j]<>e[i])then e[j]:=e[i];
      inc(i);dec(j);
    end;
    res:=e+res;
    if (y>1)then res:='+' + res;
    dec(y);
    dec(x,q);  
  end;
  writeln(res);
end.