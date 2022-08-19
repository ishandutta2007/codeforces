{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  t,i,j,p,h,m,k,n: longint;
  pred,ss,ff: array [0..5100010] of longint;
  was,q: array [0..11] of longint;
  b,pat,last,deg,ws: array [0..123456] of longint;
  a: array [0..123456,0..11] of longint;

procedure rec(v,w:longint);
var
  i: longint;
begin
  if v = k+1 then
  begin
    inc(n);
    for i:=1 to k do a[n,i]:=q[i];
    b[n]:=w;
    exit;
  end;
  for i:=1 to w do
  begin
    q[v]:=i;
    rec(v+1,w);
  end;
  q[v]:=w+1;
  rec(v+1,w+1);
end;

function find():longint;
var
  ll,rr,xx,i: longint;
  ok: boolean;
begin
  ll:=1; rr:=n;
  while ll < rr do
  begin
    xx:=(ll+rr) shr 1;
    ok:=True;
    for i:=1 to k do
      if q[i] <> a[xx,i] then
      begin
        if q[i] < a[xx,i] then rr:=xx-1
        else ll:=xx+1;
        ok:=False;
        break;
      end;
    if ok then
    begin
      find:=xx;
      exit;
    end;
  end;
  find:=ll;
end;

procedure rec2(q,v:longint);
var
  i,j,min,km,ii,p: longint;
  first: boolean;
begin
  if q = n then
  begin
    pat[q]:=v;
    writeln(n);
    for ii:=1 to n do
    begin
      i:=pat[ii];
      for j:=1 to b[i] do
      begin
        write('{');
        first:=True;
        for p:=1 to k do
          if a[i,p] = j then
          begin
            if not first then write(',');
            first:=False;
            write(p);
          end;
        write('}');
        if j < b[i] then write(',');
      end;
      writeln;
    end;
    halt;
  end;
  ws[v]:=1;
  min:=maxlongint; km:=0;
  j:=last[v];
  while j > 0 do
  begin
    if ws[ff[j]] = 0 then
      if deg[ff[j]] < min then
      begin
        min:=deg[ff[j]];
        km:=ff[j];
      end;
    j:=pred[j];
  end;
  if km = 0 then exit;
  j:=last[v];
  while j > 0 do
  begin
    dec(deg[ff[j]]);
    j:=pred[j];
  end;
  pat[q]:=v;
  rec2(q+1,km);
  j:=last[v];
  while j > 0 do
  begin
    dec(deg[ff[j]]);
    j:=pred[j];
  end;
  ws[v]:=0;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(k);
  n:=0; q[1]:=1;
  rec(2,1);
  m:=0;
  fillchar(ws,sizeof(ws),0);
  for i:=1 to n do
  begin
    ws[i]:=i;
    for j:=1 to k do
      for p:=1 to b[i]+1 do
      begin
        if p > k then continue;
        for h:=1 to k do q[h]:=a[i,h];
        q[j]:=p;
        for h:=1 to k do was[h]:=0;
        t:=0;
        for h:=1 to k do
        begin
          if was[q[h]] = 0 then
          begin
            inc(t);
            was[q[h]]:=t;
          end;
          q[h]:=was[q[h]];
        end;
        inc(m);
        ss[m]:=i;
        ff[m]:=find();
        if ws[ff[m]] = i then dec(m)
        else ws[ff[m]]:=i;
      end;
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(deg,sizeof(deg),0);
  for i:=1 to m do inc(deg[ss[i]]);
  fillchar(ws,sizeof(ws),0);
  rec2(1,1);
  close(input);
  close(output);
end.