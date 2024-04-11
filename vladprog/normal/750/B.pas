var
  n,k,i,t,c:longint;
  dir:string;

begin
  readln(n);
  c:=20000;
  for i:=1 to n do
    begin
      readln(t,dir);
      if (dir=' North')or(dir=' South')
        then
          begin
            if dir=' North'
              then inc(c,t)
              else dec(c,t);
            if (c<0)or(c>20000) then
              begin
                writeln('No');
                exit
              end
          end
        else
          if (c<=0)or(c>=20000) then
            begin
              writeln('No');
              exit
            end
    end;
  if c=20000
    then writeln('Yes')
    else writeln('No')
end.