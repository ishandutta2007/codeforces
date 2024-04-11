var
  name:array[0..500500]of ansistring;
  kg,j,ma,mb,mc,i,n,x:longint;
  ka,kb,kc:array[0..500500]of longint;
  s:ansistring;
  first:boolean;

begin
  readln(n);
  ma:=-1;mb:=-1;mc:=-1;
  for i:=1 to n do begin
    readln(s);
    x:=pos(' ',s);
    val(copy(s,1,x-1),kg);
    delete(s,1,x);
    name[i]:=s;
    ka[i]:=0;kb[i]:=0;kc[i]:=0;
    for j:=1 to kg do begin
      readln(s);
      delete(s,6,1);
      delete(s,3,1);
      if (s[2]=s[1])and(s[3]=s[2])and(s[4]=s[3])and(s[5]=s[4])and(s[6]=s[5])then inc(ka[i])else
      if (s[2]<s[1])and(s[3]<s[2])and(s[4]<s[3])and(s[5]<s[4])and(s[6]<s[5])then inc(kb[i])else
      inc(kc[i]);
    end;
    if (ka[i]>ma)then ma:=ka[i];
    if (kb[i]>mb)then mb:=kb[i];
    if (kc[i]>mc)then mc:=kc[i];
  end;
  write('If you want to call a taxi, you should call: ');
  first:=true;
  for i:=1 to n do 
    if (ka[i]=ma)then begin
      if (not first)then write(', ');
      first:=false;
      write(name[i]);
    end;
  writeln('.');

  write('If you want to order a pizza, you should call: ');
  first:=true;
  for i:=1 to n do 
    if (kb[i]=mb)then begin
      if (not first)then write(', ');
      first:=false;
      write(name[i]);
    end;
  writeln('.');

  write('If you want to go to a cafe with a wonderful girl, you should call: ');
  first:=true;
  for i:=1 to n do 
    if (kc[i]=mc)then begin
      if (not first)then write(', ');
      first:=false;
      write(name[i]);
    end;
  writeln('.');
end.