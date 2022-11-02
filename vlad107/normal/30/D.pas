var
  x:array[0..500500]of int64;
  u,xx,yy:int64;
  cr,res:extended;
  l,r,n,k,i:longint;

  procedure qs(l,r:longint);
    var
      i,j:longint;
      tmp,xx:int64;
      
    begin
      xx:=x[l+random(r-l+1)];
      i:=l;j:=r;
      while (i<=j)do begin
        while (xx>x[i])do inc(i);
        while (xx<x[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
    
  function dist(x1,y1,x2,y2:int64):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;
    
  function min(x,y:extended):extended;
    begin
      if (x<y)then min:=x else min:=y;
    end;
    
  function solve(l,r:longint):extended;
    begin
      if (l>r)then solve:=0 else 
      solve:=x[r]-x[l]+min(dist(xx,yy,x[r],0),dist(xx,yy,x[l],0));
    end;

begin
  randomize;
  read(n,k);
  for i:=1 to n do read(x[i]);
  if (k<=n)then u:=x[k];
  qs(1,n);
  read(xx,yy);
  if (k=n+1)then begin
    writeln(solve(1,n):0:10);
    exit;
  end;
  for i:=1 to n do if (x[i]=u)then k:=i;
  l:=1;r:=n;
  res:=dist(x[k],0,xx,yy)+solve(l,r);
  for i:=1 to n do begin
    if (i>=k)then begin
      cr:=x[k]-x[1]+x[i]-x[1]+dist(x[i],0,xx,yy)+solve(i+1,n);
      if (cr<res)then res:=cr;
      cr:=x[i]-x[k]+x[i]-x[1]+dist(x[1],0,xx,yy)+solve(i+1,n);
      if (cr<res)then res:=cr;
    end;
    if (i<=k)then begin
      cr:=x[n]-x[k]+x[n]-x[i]+dist(x[i],0,xx,yy)+solve(1,i-1);
      if (cr<res)Then res:=cr;
      cr:=x[k]-x[i]+x[n]-x[i]+dist(x[n],0,xx,yy)+solve(1,i-1);
      if (cr<res)then res:=cr;
    end;
  end;
  writeln(res:0:10);
end.