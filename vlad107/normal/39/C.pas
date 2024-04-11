{$r-,s-,i-,q-,O+}
type
  okr = record
    p,t,i,r,u : longint;
  end;
var
  i,j,kol,n,x,y,o_0 : longint;
  tmp : okr;
  ff : array [0..5000,0..5000] of longint;
  f : array [1..4000] of longint;
  a : array [1..5000] of okr;
  ok : boolean;

  function Srav(x,y : okr) : boolean;
  begin
    if (x.p>y.p)
      then begin srav:=true; exit; end;
    if (x.p=y.p) and (x.t=1) and (y.t=2)
      then begin srav:=true; exit; end;
    if (x.p=y.p) and (x.t=1) and (y.t=1) and (x.r<y.r)
      then begin srav:=true; exit; end;
    if (x.p=y.p) and (x.t=2) and (y.t=2) and (x.r>y.r)
      then begin srav:=true; exit; end;
    srav:=false;
  end;

  function max(a,b:longint):longint;
    begin
      if a<b
        then max:=b
        else max:=a;
    end;

  function rec(l,r:longint):longint;
    var
      m:longint;
    begin
      if ff[l,r]<>-1 then begin rec:=ff[l,r]; exit; end;
      if l>=r then begin rec:=0; exit; end;
      if (a[l].t=2) then begin m:=rec(l+1,r); ff[l+1,r]:=m; rec:=m; exit; end;
      if (a[r].t=1) then begin m:=rec(l,r-1); ff[l,r-1]:=m; rec:=m; exit; end;
      if (a[l].u>r) then begin m:=(rec(l+1,r)); ff[l+1,r]:=m; rec:=m; exit; end;
      m:=0;
      m:=max(rec(l+1,r),rec(l+1,a[l].u-1)+rec(a[l].u+1,r)+1);
      ff[l,r]:=m;
      rec:=m;
    end;

  function rec2(l,r:longint):longint;
    var
      a1,b1,m :longint;
    begin
      if l>=r then exit;
      if (a[l].t=2) then begin rec2:=(rec2(l+1,r)); exit; end;
      if (a[r].t=1) then begin rec2:=(rec2(l,r-1)); exit; end;
      if (a[l].u>r) then begin rec2:=(rec2(l+1,r)); exit; end;
      m:=0;
      a1:=rec(l+1,r);
      b1:=rec(l+1,a[l].u-1)+rec(a[l].u+1,r)+1;
      if a1>b1
        then rec2(l+1,r)
        else begin
          f[a[l].i]:=1;
          rec2(l+1,a[l].u-1);
          rec2(a[l].u+1,r);
        end;
      rec2:=m;
    end;

  procedure QSort(l,r : longint);
  var
    i,j : longint;
    x,y : okr;
  begin
    i:=l; j:=r; x:=a[(l+r) shr 1];
    repeat
      while Srav(x,a[i]) do inc(i);
      while Srav(a[j],x) do dec(j);
      if j<i then break;
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    until j<i;
    if l<j then QSort(l,j);
    if i<r then QSort(i,r);
  end;

begin
  {assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);}
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y);
      inc(kol);
      a[kol].p:=x-y;
      a[kol].t:=1;
      a[kol].i:=i;
      a[kol].r:=y;
      inc(kol);
      a[kol].p:=x+y;
      a[kol].t:=2;
      a[kol].i:=i;
      a[kol].r:=y;
    end;
  QSort(1,kol);
  {for i:=1 to kol-1 do
    for j:=1 to kol-1 do
      if Srav(a[j],a[j+1])
        then begin
          tmp:=a[j];
          a[j]:=a[j+1];
          a[j+1]:=tmp;
        end;}
  for i:=1 to kol-1 do
    for j:=i+1 to kol do
      if (a[i].t=1) and (a[j].t=2) and (a[i].i=a[j].i)
        then a[i].u:=j;
  for i:=0 to kol do
    for j:=0 to kol do ff[i,j]:=-1;
  fillchar(f,sizeof(f),0);
  o_0:=rec(1,kol);
  rec2(1,kol);
  writeln(o_0);
  for i:=1 to kol do
    if f[i]=1 then write(i,' ');
{  close(input); close(output);      }
end.