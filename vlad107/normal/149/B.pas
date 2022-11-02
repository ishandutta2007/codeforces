var
  s1,s2:ansistring;
  i,n1,n2:longint;
  zero:boolean;
  a1,a2:array[0..100]of longint;

  function ok(base:longint):boolean;
    var
      cr,i:longint;
      x:int64;

    begin
      ok:=false;
      x:=1;
      cr:=0;
      for i:=n1 downto 1 do begin
        if (a1[i]>=base)then exit;
        if (x*a1[i]+cr>23)then exit;
        cr:=cr+x*a1[i];
        x:=x*base;
      end;
      x:=1;
      cr:=0;
      for i:=n2 downto 1 do begin
        if (a2[i]>=base)then exit;
        if (x*a2[i]+cr>59)then exit;
        cr:=cr+x*a2[i];
        x:=x*base;
      end;
      ok:=true;
    end;

begin
  readln(s2);
  s1:=copy(s2,1,pos(':',s2)-1);
  delete(s2,1,pos(':',s2));

  n1:=length(s1);
  for i:=1 to n1 do 
    if (s1[i] in ['0'..'9'])
      then a1[i]:=ord(s1[i])-48 
      else a1[i]:=ord(s1[i])-55;

  n2:=length(s2);
  for i:=1 to n2 do
    if (s2[i] in ['0'..'9'])
      then a2[i]:=ord(s2[i])-48
      else a2[i]:=ord(s2[i])-55;

  if (ok(100))then writeln(-1)else begin
    zero:=true;
    for i:=2 to 100 do 
      if (ok(i))then begin 
        write(i,' ');
        zero:=false;
      end;
    if (zero)then writeln(0) else writeln;
  end;
end.