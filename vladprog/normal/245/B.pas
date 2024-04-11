var
  s:string;
  f,i:longint;
  u:boolean;

begin
  readln(s);
  if s[1]='h'
    then
      begin
        write('http://');
        f:=5
      end
    else
      begin
        write('ftp://');
        f:=4
      end;
  u:=false;
  for i:=f to length(s) do
    begin
      if (s[i]='r')and(s[i+1]='u')and(not u)and(i<>f)
        then continue;
      if (s[i-1]='r')and(s[i]='u')and(not u)and(i<>(f+1))
        then
          begin
            write('.ru');
            if i<>length(s) then
              begin
                write('/');
                u:=true
              end
          end
        else write(s[i])
    end
end.