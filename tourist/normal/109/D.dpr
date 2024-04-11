{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a1,a3,a,b,c: array [0..400010] of longint;
  a2: array [0..400010] of char;
  was: array [0..400010] of boolean;
  ok: boolean;
  ka,n,i,good,j,x,p: longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure add(x:longint;y:char;z:longint);
begin
  inc(ka);
  a1[ka]:=x;
  a2[ka]:=y;
  a3[ka]:=z;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do
  begin
    a[i]:=b[i];
    c[i]:=i;
  end;
  Sort(1,n);
  ok:=True;
  for i:=1 to n do
    if a[i] <> b[i] then
    begin
      ok:=False;
      break;
    end;
  if ok then
  begin
    writeln(0);
    halt;
  end;
  good:=0;
  for i:=1 to n do
  begin
    good:=i; x:=b[i];
    while x > 0 do
    begin
      j:=x mod 10;
      if (j <> 4) and (j <> 7) then
      begin
        good:=0;
        break;
      end;
      x:=x div 10;
    end;
    if good > 0 then break;
  end;
  if good = 0 then
  begin
    writeln(-1);
    halt;
  end;
  fillchar(was,sizeof(was),False);
  ka:=0;
  for i:=1 to n do
    if not was[i] then
    begin
      ok:=was[good];
      was[i]:=True;
      p:=c[i];
      while not was[p] do
      begin
        was[p]:=True;
        p:=c[p];
      end;
      if (not ok) and was[good] then continue;
      add(good,' ',p);
      p:=i;
      while c[p] <> i do
      begin
        add(p,' ',c[p]);
        p:=c[p];
      end;
      add(p,' ',good);
    end;
  p:=good;
  while c[p] <> good do
  begin
    add(p,' ',c[p]);
    p:=c[p];
  end;
  writeln(ka);
  for i:=1 to ka do writeln(a1[i],a2[i],a3[i]);
  close(input);
  close(output);
end.