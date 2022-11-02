{$r-,q-,s-,i-,o+}
var
  n,i:longint;
  a:array[0..100500]of longint;
  f,next:array[0..1111,0..1111]of longint;
  function max(x,y:longint):longint;
    begin
      if (x>y)then max:=x else max:=y;
    end;
  procedure rec(x,y:longint);
    var
      cr:longint;
    begin
      if (f[x][y]>=0)then exit;
      if (y=n)then begin
        f[x][y]:=max(a[x],a[y]);
        exit;
      end;
      rec(y+1,y+2);
      f[x][y]:=f[y+1][y+2]+max(a[x],a[y]);
      next[x][y]:=1;
      rec(x,y+2);
      cr:=f[x][y+2]+max(a[y],a[y+1]);
      if (cr<f[x][y])then begin
        f[x][y]:=cr;
        next[x][y]:=2;
      end;
      rec(y,y+2);
      cr:=f[y][y+2]+max(a[x],a[y+1]);
      if (cr<f[x][y])then begin
        f[x][y]:=cr;
        next[x][y]:=3;
      end;
    end;
  procedure rec2(x,y:longint);
    begin
      if (y=n)then begin
        if (a[y]=0)
          then writeln(x)
          else writeln(x,' ',y);
        exit;
      end;
      case (next[x][y])of
        1:begin
            writeln(x,' ',y);
            rec2(y+1,y+2);
          end;
        2:begin
            writeln(y,' ',y+1);
            rec2(x,y+2);
          end;
        3:begin 
            writeln(x,' ',y+1);
            rec2(y,y+2);
          end;
      end;
    end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  if (n and 1=1)then begin
    inc(n);a[n]:=0;
  end;
  fillchar(f,sizeof(f),$FF);
  rec(1,2);
  writeln(f[1][2]);
  rec2(1,2);
end.