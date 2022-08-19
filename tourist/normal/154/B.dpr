{$R-,S-,Q-,I-,O+}
var
  x,n,m,i,j,q,ok: longint;
  g: array [0..100010,0..22] of longint;
  b,kg: array [0..100010] of longint;
  ch: char;
  a: array [0..100010] of boolean;
begin
  read(n,m);
  for i:=1 to n do
  begin
    kg[i]:=0;
    x:=i;
    for j:=2 to i-1 do
      if j*j > x then break else
      if x mod j = 0 then
      begin
        inc(kg[i]);
        g[i,kg[i]]:=j;
        while x mod j = 0 do x:=x div j;
      end;
    if x > 1 then
    begin
      inc(kg[i]);
      g[i,kg[i]]:=x;
    end;
  end;
  fillchar(a,sizeof(a),False);
  fillchar(b,sizeof(b),0);
  for q:=1 to m do
  begin
    read(ch);
    while not (ch in ['-','+']) do read(ch);
    read(x);
    if ch = '+' then
    begin
      if a[x] then writeln('Already on') else
      begin
        ok:=0;
        for j:=1 to kg[x] do
          if b[g[x,j]] > 0 then ok:=b[g[x,j]];
        if ok > 0 then writeln('Conflict with ',ok) else
        begin
          writeln('Success');
          a[x]:=True;
          for j:=1 to kg[x] do b[g[x,j]]:=x;
        end;
      end;
    end else
    if not a[x] then writeln('Already off') else
    begin
      writeln('Success');
      a[x]:=False;
      for j:=1 to kg[x] do b[g[x,j]]:=0;
    end;
  end;
end.