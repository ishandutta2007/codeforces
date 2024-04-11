{$r-,q-,s-,i-,o+}
var
  name:array[0..500]of string;
  cost:array[0..500]of longint;
  s:string;
  ch:char;
  k,ka,n,m,i,j,x:longint;
  tk:extended;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m,tk);
  k:=trunc(tk*100);
  ka:=0;
  for i:=1 to n do begin
    read(ch);
    while not(ch in ['a'..'z'])do read(ch);
    s:='';
    while (ch in ['a'..'z'])do begin
      s:=s+ch;
      read(ch);
    end;
    readln(x);
    x:=x*k div 100;
    if (x<100)then continue;
    inc(ka);
    name[ka]:=s;
    cost[ka]:=x;
  end;
  for i:=1 to m do begin
    readln(s);
    j:=1;
    while (j<=ka)and(name[j]<>s)do inc(j);
    if (j>ka)then begin
      inc(ka);
      name[ka]:=s;
      cost[ka]:=0;
    end;
  end;
  for i:=1 to ka-1 do 
    for j:=1 to ka-1 do 
      if (name[j]>name[j+1])then begin
        s:=name[j];name[j]:=name[j+1];name[j+1]:=s;
        x:=cost[j];cost[j]:=cost[j+1];cost[j+1]:=x;
      end;
  writeln(ka);
  for i:=1 to ka do writeln(name[i],' ',cost[i]);      
  close(output);close(input);
end.