var
  tt,kt,n,s,i,j,x,y:longint;
  used:array[1..6]of boolean;

begin
  read(n,s);
  for i:=1 to n do begin
    read(x,y);
    if (i=1)then continue;
    s:=7-s;
    for j:=1 to 6 do used[j]:=false;
    used[s]:=true;
    used[x]:=true;
    used[y]:=true;
    used[7-x]:=true;
    used[7-y]:=true;
    kt:=0;
    for j:=1 to 6 do 
      if (not used[j])then begin
        inc(kt);
        tt:=j;
      end;    
    if (kt<>1)then begin
      writeln('NO');
      exit;
    end;
    s:=tt;
  end;
  writeln('YES');
end.