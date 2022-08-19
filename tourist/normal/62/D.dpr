{$R-,S-,Q-,I-,O+}
var
  x,deg,last: array [0..111] of longint;
  ss,ff,pred,path: array [0..4444] of longint;
  was: array [0..111] of boolean;
  g,a: array [0..111,0..111] of byte;
  q,j,pr,w,e,st,i,u,n,m,mm: longint;

procedure build();
var
  i,j: longint;
begin
  mm:=0;
  for i:=1 to n do
    for j:=1 to n do
      if a[i,j] = 1 then
      begin
        inc(mm);
        ss[mm]:=i;
        ff[mm]:=j;
      end;
end;

function exists(st,fin,v1,v2:longint):boolean;
var
  i,j: longint;
begin
  for i:=1 to n do last[i]:=0;
  for i:=1 to n do deg[i]:=0;
  for i:=1 to mm do
    if ((ss[i] <> v1) or (ff[i] <> v2)) and
       ((ff[i] <> v1) or (ss[i] <> v2)) then
    begin
      pred[i]:=last[ss[i]];
      last[ss[i]]:=i;
      inc(deg[ss[i]]);
    end;
  for i:=1 to n do
  begin
    j:=0;
    if i = st then j:=1-j;
    if i = fin then j:=1-j;
    if deg[i] and 1 <> j then
    begin
      exists:=False;
      exit;
    end;
  end;
  for i:=1 to n do was[i]:=False;
  i:=1; e:=1;
  x[1]:=st;
  was[st]:=True;
  while i <= e do
  begin
    j:=last[x[i]];
    while j > 0 do
    begin
      if not was[ff[j]] then
      begin
        inc(e);
        x[e]:=ff[j];
        was[x[e]]:=True;
      end;
      j:=pred[j];
    end;
    inc(i);
  end;
  for i:=1 to n do
    if (deg[i] > 0) and (not was[i]) then
    begin
      exists:=False;
      exit;
    end;
  exists:=True;
end;


begin
  read(n,m);
  for i:=1 to m+1 do read(path[i]);
  fillchar(g,sizeof(g),0);
  for i:=1 to m do
  begin
    g[path[i],path[i+1]]:=1;
    g[path[i+1],path[i]]:=1;
  end;
  st:=path[1];
  for q:=m+1 downto 2 do
  begin
    for i:=1 to n do
      for j:=1 to n do a[i,j]:=g[i,j];
    for i:=1 to q-2 do
    begin
      a[path[i],path[i+1]]:=0;
      a[path[i+1],path[i]]:=0;
    end;
    for u:=path[q]+1 to n do
    begin
      if a[path[q-1],u] = 0 then continue;
      a[path[q-1],u]:=0;
      a[u,path[q-1]]:=0;
      build();
      if exists(u,st,0,0) then
      begin
        for i:=1 to q-1 do write(path[i],' ');
        write(u);
        pr:=u;
        for w:=q+1 to m+1 do
        begin
          build();
          for i:=1 to n do
            if a[pr,i] = 1 then
              if exists(i,st,pr,i) then
              begin
                write(' ',i);
                a[pr,i]:=0;
                a[i,pr]:=0;
                pr:=i;
                break;
              end;
        end;
        writeln;
        halt;
      end;
      a[path[q-1],u]:=1;
      a[u,path[q-1]]:=1;
    end;
  end;
  writeln('No solution');
end.