var
  s,t:ansistring;
  p:longint;

begin
  readln(s);
  p:=pos('.',s);
  if (p=0)then p:=length(s)+1;
  if (s[p-1]='9')
    then writeln('GOTO Vasilisa.')
    else begin
      if (p=length(s)+1)
        then writeln(s)
        else begin
          t:=s;
          delete(t,1,p);
          if (t[1]<'5')
            then writeln(copy(s,1,p-1))
            else begin
              s:=copy(s,1,p-1);
              p:=length(s);
              while (p>0)and(s[p]='9')do begin
                s[p]:='0';
                dec(p);
              end;
              if (p=0)then s:='1'+s else s[p]:=chr(ord(s[p])+1);
              writeln(s);  
            end;
        end; 
    end;
end.