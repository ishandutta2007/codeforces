{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  sum,j,tmp,n,a,b,m,i,sx,sy: longint;
  can: array [0..41111] of boolean;
  x,y,pred,last,xm,ym,ca,cb: array [0..41111] of longint;

procedure Sort(l,r:longint);
var
  i,j,pp,xx,yy,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  xx:=x[pp]; yy:=y[pp];
  repeat
    while x[i]*yy > xx*y[i] do inc(i);
    while x[j]*yy < xx*y[j] do dec(j);
    if i <= j then
    begin
      tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
      tmp:=y[i]; y[i]:=y[j]; y[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  if n = 3 then
  begin
    writeln('YES');
    writeln('0 0');
    writeln('1 0');
    writeln('0 2');
    halt;
  end;
  fillchar(can,sizeof(can),False);
  for a:=0 to 200 do
    for b:=0 to 200 do
      if a*a+b*b <= 40000 then
      begin
        can[a*a+b*b]:=True;
        ca[a*a+b*b]:=a;
        cb[a*a+b*b]:=b;
      end;
  m:=0;
  for i:=1 to 40000 do
    if can[i] then
    begin
      inc(m);
      xm[m]:=ca[i];
      ym[m]:=cb[i];
      if m = n+1 then break;
    end;
  sx:=0; sy:=0;
  for i:=1 to n do
  begin
    inc(sx,xm[i]);
    inc(sy,ym[i]);
  end;
  if (sx+sy) and 1 = 1 then
  begin
    inc(sx,xm[n+1]);
    inc(sy,ym[n+1]);
    for i:=1 to n do
      if ((sx-xm[i])+(sy-ym[i])) and 1 = 0 then
      begin
        dec(sx,xm[i]);
//        dec(sy,ym[i]);
        xm[i]:=xm[n+1];
        ym[i]:=ym[n+1];
        break;
      end;
  end;
  if sx and 1 = 1 then
    for i:=n downto 1 do
      if (xm[i]+ym[i]) and 1 = 1 then
      begin
        tmp:=xm[i];
        xm[i]:=ym[i];
        ym[i]:=tmp;
        break;
      end;
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
  begin
    pred[i]:=last[xm[i]];
    last[xm[i]]:=i;
  end;
  sum:=0;
  for a:=200 downto 0 do
  begin
    j:=last[a];
    while j > 0 do
    begin
      if sum > 0 then xm[j]:=-xm[j];
      inc(sum,xm[j]);
      j:=pred[j];
    end;
  end;
  if sum <> 0 then while true do;
  fillchar(last,sizeof(last),0);
  for i:=1 to n do
  begin
    pred[i]:=last[ym[i]];
    last[ym[i]]:=i;
  end;
  sum:=0;
  for a:=200 downto 0 do
  begin
    j:=last[a];
    while j > 0 do
    begin
      if sum > 0 then ym[j]:=-ym[j];
      inc(sum,ym[j]);
      j:=pred[j];
    end;
  end;
  if sum <> 0 then while true do;
  writeln('YES');
  m:=0;
  for i:=1 to n do
    if (ym[i] > 0) or (ym[i] = 0) and (xm[i] > 0) then
    begin
      inc(m);
      x[m]:=xm[i];
      y[m]:=ym[i];
    end;
  if m > 0 then Sort(1,m);
  sx:=0; sy:=0;
  for i:=1 to m do
  begin
    writeln(sx,' ',sy);
    sx:=sx+x[i];
    sy:=sy+y[i];
  end;
  m:=0;
  for i:=1 to n do
    if not ((ym[i] > 0) or (ym[i] = 0) and (xm[i] > 0)) then
    begin
      inc(m);
      x[m]:=xm[i];
      y[m]:=-ym[i];
    end;
  if m > 0 then Sort(1,m);
  for i:=m downto 1 do
  begin
    writeln(sx,' ',sy);
    sx:=sx+x[i];
    sy:=sy-y[i];
  end;
  close(input);
  close(output);
end.