{$r-,q-,s-,i-,o+}
var
  tmp,i,j,n,m,k:longint;
  ans:int64;
  rev:array[0..500500]of longint;
  a,b:array[0..555,0..555]of longint;
  c:array[0..555,0..555]of int64;
  
  procedure check(l:longint);
    var
      t,i,j:longint;
      cr:int64;
    begin
      for i:=1 to k do rev[i]:=-1;
      for i:=1 to n do 
        for j:=1 to m do 
          if (a[i][j]<>0)then begin
            if (rev[a[i][j]]=-1)then rev[a[i][j]]:=b[i][j] else
            if (rev[a[i][j]]<>b[i][j])then exit;
          end;
      t:=0;
      for i:=1 to k do if (rev[i]<>-1)then inc(t);
      for i:=1 to k do rev[i]:=-1;
      for i:=1 to n do 
        for j:=1 to m do 
          if (a[i][j]<>0)then begin
            if (rev[b[i][j]]=-1)then rev[b[i][j]]:=a[i][j] else
            if (rev[b[i][j]]<>a[i][j])then exit;
          end;
      cr:=c[k-t][l-t];
      for i:=1 to l-t do cr:=cr*i;
      inc(ans,cr);
    end;
  
  procedure rec(x,y,max:longint);
    var
      j,nx,ny,i:longint;
      used:array[0..10]of boolean;
    begin
      if (x=n)then begin
        check(max);
        exit;
      end;
      nx:=x;ny:=y+1;
      if (ny>m)then begin
        inc(nx);ny:=1;
      end;
      for i:=1 to k do used[i]:=false;
      for i:=1 to n do 
        for j:=1 to m do 
          if (b[i][j]<>0)and(((i<=x)and(j<=y))or((x<=i)and(y<=j)))then used[b[i][j]]:=true;
      for i:=1 to max+1 do begin
        if (i>k)then break;
        if (used[i])then continue;
        b[x][y]:=i;
        if (i=max+1)then rec(nx,ny,max+1)else rec(nx,ny,max);    
        b[x][y]:=0;
      end;
    end;

begin
  read(n,m,k);
  if (n+m-1>k)then begin
    writeln(0);
    exit;
  end;
  for i:=0 to k do 
    for j:=0 to k do 
      if (j>i)then c[i][j]:=0 else
      if (j=i)or(j=0)then c[i][j]:=1 else
      c[i][j]:=c[i-1][j]+C[i-1][j-1];
  for i:=1 to n do for j:=1 to m do read(a[i][j]);
  if (n>m)then begin
    for i:=1 to n do 
      for j:=1 to m do 
        b[m-j+1][n-i+1]:=a[i][j];
    tmp:=n;n:=m;m:=tmp;
    for i:=1 to n do 
      for j:=1 to m do a[i][j]:=b[i][j];
    for i:=1 to n do begin
      for j:=1 to m do write(a[i][j],' ');
      writeln;
    end;
  end;
  for i:=1 to m do b[n][i]:=i;
  rec(1,1,m);
  writeln(ans mod 1000000007);
end.