const
  MAXN = 100000;  

var
  n,v,i:longint;
  mid,sum,l,r:double;
  a:array[1..MAXN] of double;
  b:array[1..MAXN] of longint;

  function ok(x:double):boolean;
    var
      i:longint;
    begin
      for i:=1 to n do 
        if (x*a[i]>b[i])then begin
          ok:=false;
          exit;
        end;
      ok:=true;
    end;

begin
  read(n,v);
  sum:=0;
  for i:=1 to n do begin
    read(a[i]);
    sum:=sum+a[i];
  end;
  for i:=1 to n do read(b[i]);
  for i:=1 to n do a[i]:=a[i]/sum;
  l:=0;
  r:=v;
  for i:=1 to 10000 do begin
    mid:=(l+r)/2;
    if (ok(mid))
      then l:=mid
      else r:=mid;
  end;
  writeln(l:0:30);
end.