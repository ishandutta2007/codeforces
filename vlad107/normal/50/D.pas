{$r-,q-,s-,i-,o+}
const
  eps=1e-9;

var
  i,j,n,k:longint;
  cv,x0,y0,x,y,ee,ll,rr:extended;
  dx:array[1..10000] of extended;
  f:array[1..111,0..111] of extended;

  function min(x,y:extended):extended;
    begin
      if (x<y)then min:=y else min:=x;
    end;

  function ver(d,r:extended):extended;
    begin
      if (r>=d)
        then ver:=1
        else begin
          if (abs(r)<eps)
            then ver:=0
            else ver:=exp(1-(d*d)/(r*r));
        end;
    end;

  function ok(xx:extended):boolean;
    begin
      for i:=1 to n+1 do
        for j:=0 to n do f[i][j]:=0.0;
      f[1][0]:=1;
      for i:=1 to n do
        for j:=0 to n do begin
          cv:=ver(dx[i],xx);
          f[i+1][j]:=f[i+1][j]+f[i][j]*cv;
          if (j<n)then f[i+1][j+1]:=f[i+1][j+1]+f[i][j]*(1-cv);
        end;
      cv:=0.0;
      for i:=k+1 to n do
        cv:=cv+f[n+1][i];
      ok:=cv<=ee;
    end;

begin
  read(n,k,ee,x0,y0);
  ee:=ee/1000;
  k:=n-k;
  for i:=1 to n do begin
    read(x,y);
    dx[i]:=sqrt((x0-x)*(x0-x)+(y0-y)*(y0-y));
  end;
  ll:=0;rr:=1e9;
  while (rr-ll>eps) do
    if (ok((ll+rr)/2))
      then rr:=(ll+rr)/2
      else ll:=(ll+rr)/2;
  writeln(ll:0:10);
end.