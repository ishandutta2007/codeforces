uses math;

type
  font=record
    b,p,m:longint
  end;

var
  n,c,d,i,j,b,p,pc,pd,m,mc,md,mt:longint;
  s:char;
  sc,sd:array[1..100000]of font;

procedure SortC(L, R : Longint);
var
  i, j, x: longint;
  t:font;
begin
  i := L; 
  j := R; 
  x := sc[(i + j)div 2].p;
  repeat
    while sc[i].p < x do inc(i);
    while sc[j].p > x do dec(j);
    if i <= j then begin
      t := sc[i]; 
      sc[i] := sc[j]; 
      sc[j] := t;
      inc(i); 
      dec(j);
    end;
  until i > j;
  if i < R then SortC(i, R);
  if j > L then SortC(L, j);
end;

procedure SortD(L, R : Longint);
var
  i, j, x: longint;
  t:font;
begin
  i := L; 
  j := R; 
  x := sd[(i + j)div 2].p;
  repeat
    while sd[i].p < x do inc(i);
    while sd[j].p > x do dec(j);
    if i <= j then begin
      t := sd[i]; 
      sd[i] := sd[j]; 
      sd[j] := t;
      inc(i); 
      dec(j);
    end;
  until i > j;
  if i < R then SortD(i, R);
  if j > L then SortD(L, j);
end;

begin
  read(n,c,d);
  pc:=0;
  pd:=0;
  for i:=1 to n do
    begin
      read(b,p,s,s);
      if s='C'
        then
          begin
            inc(pc);
            sc[pc].b:=b;
            sc[pc].p:=p
          end
        else
          begin
            inc(pd);
            sd[pd].b:=b;
            sd[pd].p:=p
          end
    end;
  sortc(1,pc);
  sortd(1,pd);
  i:=1;
  mc:=0;
  while (sc[i].p<=c)and(i<=pc) do
    begin
      mc:=max(mc,sc[i].b);
      inc(i)
    end;
  i:=1;
  md:=0;
  while (sd[i].p<=d)and(i<=pd) do
    begin
      md:=max(md,sd[i].b);
      inc(i)
    end;
  if min(mc,md)=0
    then m:=0
    else m:=mc+md;
  mc:=0;
  sc[1].m:=sc[1].b;
  for i:=1 to pc do
    sc[i].m:=max(sc[i-1].m,sc[i].b);
  j:=1;
  for i:=pc downto 1 do
    begin
      while (sc[j].p<=c-sc[i].p)and(j<i)do
        inc(j);
      if j=1 then
        continue;
      dec(j);
      mc:=max(mc,sc[i].b+sc[min(j,i-1)].m)
    end;
  md:=0;
  sd[1].m:=sd[1].b;
  for i:=1 to pd do
    sd[i].m:=max(sd[i-1].m,sd[i].b);
  j:=1;
  for i:=pd downto 1 do
    begin
      while (sd[j].p<=d-sd[i].p)and(j<i)do
        inc(j);
      if j=1 then
        continue;
      dec(j);
      md:=max(md,sd[i].b+sd[min(j,i-1)].m);
      //writeln(i,' ',j,' ',min(j,i-1),' ',sd[i].b,' ',sd[min(j,i-1)].m)
    end;
  writeln(max(m,max(mc,md)))
end.