uses
  math;

var
  n,i,m,k,len:longint;
  c:char;
  b:boolean;

begin
  readln(n);
  for i:=1 to n do
    begin
      read(c);
      case c of
        '_':
          begin
            if b
              then begin if len<>0 then inc(k) end
              else m:=max(m,len);
            len:=0
          end;
        '(':
          begin
            m:=max(m,len);
            len:=0;
            b:=true
          end;
        ')':
          begin
            if len<>0 then inc(k);
            len:=0;
            b:=false
          end;
        else inc(len)
      end
    end;
  m:=max(m,len);
  writeln(m,' ',k)
end.