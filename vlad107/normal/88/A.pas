const
  tt:array[1..12]of string=('C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'B', 'H');
var
  s:string;
  x,y,z:longint;
  function f(var s:string):longint;
    var
      i:longint;
      p:string;
    begin
      p:=copy(s,1,pos(' ',s)-1);
      delete(s,1,pos(' ',s));
      i:=1;
      while (tt[i]<>p)do inc(i);
      f:=i;
    end;
  function dis(x,y:longint):longint;
    var
      res:longint;
    begin
      res:=0;
      while (x<>y)do begin
        inc(res);
        inc(x);
        if (x>12)then dec(x,12);
      end;
      dis:=res;
    end;
  procedure sol(x,y,z:longint);
    var
      d1,d2:longint;
    begin
      d1:=dis(x,y);
      d2:=dis(y,z);
      if (d1=4)and(d2=3)then begin
        writeln('major');
        halt(0);
      end;
      if (d1=3)and(d2=4)then begin
        writeln('minor');
        halt(0);
      end;
    end;
begin
  readln(s);
  s:=s+' ';
  x:=f(s);
  y:=f(s);
  z:=f(s);
  sol(x,y,z);
  sol(x,z,y);
  sol(y,x,z);
  sol(y,z,x);
  sol(z,x,y);
  sol(z,y,x);
  writeln('strange');
end.