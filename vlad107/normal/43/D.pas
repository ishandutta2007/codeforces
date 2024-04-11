var
  x,y,q,n,m:longint;

  procedure solve1;
    begin
      x:=1;y:=1;
      while (y<=m) do begin
        writeln(x, ' ',y);
        inc(y);
      end;
      x:=2;
      y:=m;
      q:=1;
      while (y>0) do begin
        if (q=0)
          then begin
            while (x>2) do begin
              writeln(x, ' ',y);
              dec(x);
            end;
            writeln(x, ' ',y);
          end else begin
            while (x<n) do begin
              writeln(x, ' ',y);
              inc(x);
            end;
            writeln(x, ' ',y);
          end;
        dec(y);
        q:=1-q;
      end;
      writeln('1 1');
    end;

  procedure solve2;
    begin
      x:=1;y:=1;
      while (x<=n) do begin
        writeln(x, ' ',y);
        inc(x);
      end;
      x:=n;
      y:=2;
      q:=1;
      while (x>0) do begin
        if (q=0)
          then begin
            while (y>2) do begin
              writeln(x, ' ',y);
              dec(y);
            end;
            writeln(x,' ',y);
          end else begin
            while (y<m) do begin
              writeln(x,' ',y);
              inc(y);
            end;
            writeln(x,' ',y);
          end;
        dec(x);
        q:=1-q;
      end;
      writeln('1 1');
    end;

begin
//  assign(output,'1.out');rewrite(output);
  read(n,m);
  if (n=1)and (m=1)then begin
    writeln(1);
    writeln('1 1 1 1');
    writeln('1 1');
    writeln('1 1');
    exit;
  end;
  if (n=1)and (m=2)then begin
    writeln(0);
    writeln('1 1');
    writeln('1 2');
    writeln('1 1');
    exit;
  end;
  if (n=2)and(m=1)then begin
    writeln(0);
    writeln('1 1');
    writeln('2 1');
    writeln('1 1');   
    exit;
  end;
  if (n=1) then begin
    writeln(1);
    writeln('1 ',m, ' 1 1');
    for y:=1 to m do writeln(1, ' ',y);
    writeln('1 1');
    exit;
  end;
  if (m=1)then begin
    writeln(1);
    writeln(n,' 1 1 1');
    for x:=1 to n do writeln(x,' 1');
    writeln('1 1');
    exit;
  end;
  if ((n and 1) + (m and 1) = 2)
    then begin
      writeln(1);
      writeln(n, ' 1 1 1');
      solve1;
      exit;
    end;
  writeln(0);
  if (m and 1=0)then begin
    solve1;
    exit;
  end;
  solve2;
end.