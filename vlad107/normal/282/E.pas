var
  pref,suff,a:array[0..500500]of int64;
  kb,i,n:longint;
  pw:array[0..500500]of int64;
  u:array[0..4000000]of int64;
  next:array[0..4000500,0..1]of longint;
  ans:int64;

  procedure add(x:int64);
    var
      qt,i,q:longint;
      y:int64;
    begin
      q:=0;y:=x;
      for i:=40 downto 0 do begin
        if (x>=pw[i])then begin qt:=1;x:=x-pw[i];end else qt:=0;
        if (next[q][qt]=0)then begin
          inc(kb);
          next[q][qt]:=kb;
        end;
        q:=next[q][qt];
      end;
      u[q]:=y;
    end;
    
  procedure check(x:int64);
    var
      q,qt,i:longint;
      y:int64;
    begin
      q:=0;y:=x;
      for i:=40 downto 0 do begin
        if (x>=pw[i])then begin qt:=1;x:=x-pw[i]; end else qt:=0;
        if (next[q][1-qt]=0)then q:=next[q][qt] else q:=next[q][1-qt];
      end;
      if (y xor u[q]>ans)then ans:=y xor u[q];
    end;

begin
  pw[0]:=1;for i:=1 to 40 do pw[i]:=pw[i-1]*2; 
  read(n);
  pref[0]:=0;
  suff[n+1]:=0;
  for i:=1 to n do begin
    read(a[i]);
    pref[i]:=pref[i-1]xor a[i];
    if (pref[i]>ans)then ans:=pref[i];
  end;
  for i:=n downto 1 do begin
    suff[i]:=suff[i+1]xor a[i];
    if (suff[i]>ans)then ans:=suff[i];
  end;
  for i:=1 to n do begin
    check(suff[i]);
    add(pref[i]);
  end;
  writeln(ans);
end.