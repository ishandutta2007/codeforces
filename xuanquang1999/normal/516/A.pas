const fi = '';
      fo = '';

var n, i, j, tmp: longint;
    code: integer;
    s: string;
    f: array [2..7] of longint;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n);
 readln(s);
 for i:=1 to n do
  case s[i] of
   '9':
    begin
     f[7]:=f[7]+1;
     f[3]:=f[3]+2;
     f[2]:=f[2]+1;
    end;
   '8':
    begin
     f[7]:=f[7]+1;
     f[2]:=f[2]+3;
    end;
   '6':
    begin
     f[5]:=f[5]+1;
     f[3]:=f[3]+1;
    end;
   '4':
    begin
     f[3]:=f[3]+1;
     f[2]:=f[2]+2;
    end;
   '1', '0':;
   else
    begin
     val(s[i], tmp, code);
     f[tmp]:=f[tmp]+1;
    end;
  end;

 for i:=7 downto 2 do
  for j:=1 to f[i] do write(i);
 writeln;

 close(input); close(output);
end.