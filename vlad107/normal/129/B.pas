var
  j,cr,res,n,m,x,y,i:longint;
  found:boolean;
  used,was:array[0..500500]of boolean;
  kg:array[0..500500]of longint;
  g:array[0..1111,0..1111]of longint;

begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y);
    inc(kg[x]);g[x][kg[x]]:=y;
    inc(kg[y]);g[y][kg[y]]:=x;
  end;
  res:=0;
  fillchar(was,sizeof(was),false);
  while (true)do begin
    for i:=1 to n do used[i]:=was[i];
    found:=false;
    for i:=1 to n do
      if (not was[i])then begin
        cr:=0;
        for j:=1 to kg[i]do
          if (not was[g[i][j]])then inc(cr);
        if (cr=1)then begin
          used[i]:=true;
          found:=true;
        end;
      end;
    if (found)then inc(res) else break;
    for i:=1 to n do was[i]:=used[i];
  end;
  writeln(res);
end.