var
 a,b:qword;
begin
 read(a,b);
 if ((a-b)and 1=1)
  then writeln(-1)
  else writeln((a-b)shr 1,' ',(a+b)shr 1)
end.