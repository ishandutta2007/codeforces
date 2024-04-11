{$R-,S-,Q-,I-,O+}
var
  kg,n,m,i,ka,j,g,c,p,kq: longint;
  ax,ay,w,q: array [0..100010] of longint;
  was: array [0..100010] of boolean;

procedure add(x,y:longint);
begin
  inc(ka);
  ax[ka]:=x;
  ay[ka]:=y;
end;

begin
  read(n,m);
  for i:=1 to n do w[i]:=0;
  c:=0;
  for i:=1 to m do
  begin
    read(kg);
    for j:=1 to kg do
    begin
      read(g);
      inc(c);
      w[g]:=c;
    end;
  end;
  ka:=0;
  if w[n] > 0 then
    for i:=1 to n do
      if w[i] = 0 then
      begin
        add(n,i);
        w[i]:=w[n];
        w[n]:=0;
        break;
      end;
  for i:=1 to n-1 do
    if w[i] = 0 then
    begin
      inc(c);
      w[i]:=c;
    end;
  fillchar(was,sizeof(was),False);
  for i:=1 to n-1 do
    if not was[i] then
    begin
      p:=i; kq:=0;
      while not was[p] do
      begin
        inc(kq);
        q[kq]:=p;
        was[p]:=True;
        p:=w[p];
      end;
      if kq > 1 then
      begin
        add(q[kq],n);
        for j:=kq-1 downto 1 do add(q[j],q[j+1]);
        add(n,q[1]);
      end;
    end;
  writeln(ka);
  for i:=1 to ka do writeln(ax[i],' ',ay[i]);
end.