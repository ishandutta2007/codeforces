uses math;
const fi = '';
      fo = '';
var m, s: longint;

procedure Findmin(m, s: longint);
var a: array [1..100] of longint;
    i, d: longint;
begin
 for i:=m downto 2 do
  begin
   d:=min(s-1, 9);
   a[i]:=d; s:=s-d;
  end;
 a[1]:=s;

 for i:=1 to m do write(a[i]);
 write(' ');
end;

procedure Findmax(m, s: longint);
var a: array [1..100] of longint;
    i, d: longint;
begin
 for i:=1 to m do
  begin
   d:=min(s, 9);
   a[i]:=d; s:=s-d;
  end;

 for i:=1 to m do write(a[i]);
 write(' ');
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(m, s);
 if ((s < 1) and (m > 1)) or (s > 9*m) then writeln('-1 -1')
 else
  begin
   Findmin(m, s);
   Findmax(m, s);
   writeln;
  end;

 close(input); close(output);
end.