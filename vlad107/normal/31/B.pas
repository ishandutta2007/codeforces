var
  z,res,s:ansistring;
  i:longint;
  first:boolean;

  procedure bad;
   begin
     writeln('No solution');
     halt(0);
   end;

begin
  readln(s);
  if (pos('@',s)=0)then bad;
  first:=true;
  z:='';
  res:='';
  for i:=1 to length(s) do
    if (s[i]='@') then begin
      if (z='')then bad;
      if (first)then begin
        res:=z+'@';
        first:=false;
        z:='';
        continue;
      end;
      if (length(z)<2)then bad;
      res:=res+z[1];delete(z,1,1);
      res:=res+','+z+'@';
      z:='';
    end else z:=z+s[i];
  if (z='')then bad;
  writeln(res+z);
end.