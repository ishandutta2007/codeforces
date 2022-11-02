var
  ls1,ls2,i,ans:longint;
  s1,s2:ansistring;

  procedure check(x:longint);
    var
      i:longint;
      
    begin
      if (ls2 mod x<>0)then exit;
      for i:=x+1 to ls1 do 
        if (s1[i]<>s1[i-x])then exit;
      for i:=x+1 to ls2 do 
        if (s2[i]<>s2[i-x])then exit;
      for i:=1 to x do
        if (s1[i]<>s2[i])then exit;
      inc(ans);
    end;

begin
  readln(s1);
  readln(s2);
  ls1:=length(s1);
  ls2:=length(s2);
  i:=1;
  ans:=0;
  while (i*i<=ls1)do begin
    if (ls1 mod i=0)then begin
      check(i);
      if (i*i<ls1)then check(ls1 div i);
    end;
    inc(i);
  end;
  writeln(ans);
end.