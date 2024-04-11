{$r-,q-,s-,i-,o+}
var
  ko,j,n,i,ntr,ktr:longint;
  tr:array[0..500500]of longint;
  p,s,tq:ansistring;
  
begin
  //assign(input,'input.txt');reset(input);
  readln(n);
  tq:='~';
  ntr:=-1;ktr:=0;
  for i:=1 to n do begin
    readln(s);
    p:='';
    ko:=0;
    for j:=1 to length(s)do begin
      if (s[j]='"')then inc(ko);
      if (s[j]<>' ')or(ko and 1=1)then p:=p+s[j];
    end;
    s:=p;
    if (s='try')then begin
      inc(ktr);
      tr[ktr]:=i;
      continue;
    end;
    if (copy(s,1,5)='throw')then begin
      delete(s,1,6);
      tq:=copy(s,1,pos(')',s)-1);
      ntr:=i;
      continue;
    end;
    delete(s,1,6);
    p:=copy(s,1,pos(',',s)-1);
    delete(s,1,pos(',',s));
    if (p=tq)and(tr[ktr]<=ntr)then begin
      writeln(copy(s,2,length(s)-3));
      exit;
    end;
    dec(ktr);
  end;
  writeln('Unhandled Exception');
end.