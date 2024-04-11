var
  z,s,p:string;
  xs,i,n,j,kst:longint;
  fail:array[0..111]of boolean;
  a,b:array[0..111]of string;
  koper,kpm:array[0..111]of longint;
  procedure bad;
    begin
      writeln('Suspicious');
      halt(0);
    end;
  function fnom(var s:string):longint;
    var
      q:longint;
    begin
      q:=1;
      while (q<=n)and(a[q]<>s)do inc(q);
      if (q>n)then q:=-1;
      fnom:=q;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(n);
  for i:=1 to n do a[i]:='!';
  for i:=1 to n do begin
    readln(s);
    while (s[1]=' ')do delete(s,1,1);
    delete(s,1,1);
    while (s[1]=' ')do delete(s,1,1);
    delete(s,1,6);
    while (s[1]=' ')do delete(s,1,1);
    a[i]:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    p:='';
    for j:=1 to length(s)do
      if (s[j]<>' ')then p:=p+s[j];
    b[i]:=p;
    z:='';
    kst:=0;
    koper[i]:=0;
    kpm[i]:=0;
    fail[i]:=false;
    for j:=1 to length(p)do begin
      if (p[j]in['+','-','*','/'])and(kst=0)then inc(koper[i]);
      if (p[j]in['+','-'])and(kst=0)then inc(kpm[i]);
      if (p[j]in['a'..'z','A'..'Z'])
        then z:=z+p[j]
        else begin
          xs:=fnom(z);
          if (z='')or(xs<0)then begin
            if (p[j]='(')then inc(kst);
            if (p[j]=')')then dec(kst);
            z:='';
            continue;
          end;
          fail[i]:=fail[i]or fail[xs];
          if (kst=0)then begin
            inc(kpm[i],kpm[xs]);
            inc(koper[i],koper[xs]);
          end;
          if (((j-length(z)-1>0)and(p[j-length(z)-1]='-'))or
              (p[j]='*')or
              (p[j]='/')or
              ((j-length(z)-1>0)and(p[j-length(z)-1]='*')))and(kpm[xs]>0)then fail[i]:=true;
          if (j-length(z)-1>0)and(p[j-length(z)-1]='/')and(koper[xs]>0)then fail[i]:=true;
          z:='';
        end;
      if (p[j]='(')then inc(kst);
      if (p[j]=')')then dec(kst);
    end;
    if (z<>'')then begin
      xs:=fnom(z);
      if (xs<0)then continue;
      fail[i]:=fail[i]or fail[xs];
      inc(kpm[i],kpm[xs]);
      inc(koper[i],koper[xs]);
      j:=length(p)-length(z);
      if (j>0)and(p[j]='-')and(kpm[xs]>0)then fail[i]:=true;
      if (j>0)and(p[j]='*')and(kpm[xs]>0)then fail[i]:=true;
      if (j>0)and(p[j]='/')and(koper[xs]>0)then fail[i]:=true;
    end;
  end;
  readln(s);
  p:='';
  for i:=1 to length(s)do
    if (s[i]<>' ')then p:=p+s[i];
  s:=p;
  z:='';
  for i:=1 to length(s)do
    if (s[i]in['a'..'z','A'..'Z'])
      then z:=z+s[i]
      else begin
        xs:=fnom(z);
        if (xs<0)then begin
          z:='';
          continue;
        end;
        if (fail[xs])then bad;
        if (((i-length(z)-1>0)and(s[i-length(z)-1]='-'))or
           (s[i]='*')or
           (s[i]='/')or
           ((i-length(z)-1>0)and(s[i-length(z)-1]='*')))and(kpm[xs]>0)then bad;
        if (i-length(z)-1>0)and(s[i-length(z)-1]='/')and(koper[xs]>0)then bad;
        z:='';
      end;
  if (z<>'')then begin
    xs:=fnom(z);
    if (xs>0)then begin
      if (fail[xs])then bad;
      j:=length(s)-length(z);
      if (j>0)and(s[j]='-')and(kpm[xs]>0)then bad;
      if (j>0)and(s[j]='*')and(kpm[xs]>0)then bad;
      if (j>0)and(s[j]='/')and(koper[xs]>0)then bad;
    end;
  end;
  writeln('OK');
end.