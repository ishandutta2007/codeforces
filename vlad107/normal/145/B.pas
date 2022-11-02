var
  ns,s:ansistring;
  x,i,a1,a2,a3,a4,k1,k2:longint;

  procedure check(s:ansistring);
    begin
      k1:=0;k2:=0;
      for i:=1 to length(s)do
        if (s[i]='4')then inc(k1)else inc(k2);
      if (k1>a1)then exit;
      if (k2>a2)then exit;
      k1:=a1-k1;
      k2:=a2-k2;
      if (k1>0)then begin
        x:=pos('4',s);
        if (x=0)then exit;
        ns:='';
        for i:=1 to k1 do ns:=ns+'4';
        s:=copy(s,1,x)+ns+copy(s,x+1,length(s));
      end;
      if (k2>0)then begin
        x:=length(s);
        while (x>0)and(s[x]<>'7')do dec(x);
        if (x=0)then exit;
        ns:='';
        for i:=1 to k2 do ns:=ns+'7';
        s:=copy(s,1,x)+ns+copy(s,x+1,length(s));
      end;
      writeln(s);
      halt(0);
    end;

begin
  read(a1,a2,a3,a4);
  if (a3=a4)then begin
    s:='';
    for i:=1 to a3 do s:=s+'47';
    s:=s+'4';
    check(s);

    s:='';
    for i:=1 to a3 do s:=s+'74';
    s:=s+'7';
    check(s);
    writeln(-1);
    exit;
  end;

  if (a3=a4+1)then begin
    s:='';
    for i:=1 to a3 do s:=s+'47';
    check(s);
    writeln(-1);
    exit;
  end;

  if (a4=a3+1)then begin
    s:='';
    for i:=1 to a4 do s:=s+'74';
    check(s);
    writeln(-1);
    exit;
  end;
  writeln(-1);
end.