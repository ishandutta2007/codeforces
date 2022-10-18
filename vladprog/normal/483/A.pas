var
  l,r:int64;

begin
  read(l,r);
  if odd(l)
    then inc(l);
  if (r-l)<2
    then writeln(-1)
    else writeln(l,' ',l+1,' ',l+2)
end.