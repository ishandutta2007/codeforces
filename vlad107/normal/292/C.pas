{$r-,q-,s-,i-,o+}
var
  kans,x,n,i:longint;
  ans:array[0..500500]of ansistring;
  can:array[0..500]of boolean;

  function good(x:longint):boolean;
    begin
      if (x=0)then begin
        good:=can[x];
        exit;
      end;
      good:=false;
      while (x>0)do begin
        if (not can[x mod 10])then exit;
        x:=x div 10;
      end;
      good:=true;
    end;
    
  function ok(s:ansistring):boolean;
    var
      u:longint;
    begin
      ok:=false;
      if (length(s)>1)and(s[1]='0')then exit;
      val(s,u);
      if (u>255)then exit;
      ok:=true;
    end;
    
  procedure calc(s:ansistring);
    var
      p4,p1,p2,p3:ansistring;
      i,j,k:longint;
    begin
      p1:='';
      for i:=1 to length(s)do begin
        p1:=p1+s[i];
        if (not ok(p1))then break;
        p2:='';
        for j:=i+1 to length(s)do begin
          p2:=p2+s[j];
          if (not ok(p2))then break;
          p3:='';
          for k:=j+1 to length(s)-1do begin
            p3:=p3+s[k];
            if (not ok(p3))then break;
            p4:=copy(s,k+1,length(s));
            if (not ok(p4))then continue;
            inc(kans);
            ans[kans]:=p1+'.'+p2+'.'+p3+'.'+p4;
          end;
        end;
      end;
    end;
    
  procedure rec(s:ansistring);
    var
      p:ansistring;
      i:longint;
      found:boolean;
      pc:array[0..9]of boolean;
    begin
      if (length(s)>=2)then begin
        for i:=0 to 9 do pc[i]:=can[i];
        for i:=1 to length(s)do pc[ord(s[i])-48]:=false;
        found:=false;
        for i:=0 to 9 do 
          if (pc[i])then begin
            found:=true;
            break;
          end;
        if (not found)then begin
          p:=s;
          for i:=length(s) downto 1 do p:=p+s[i];
          calc(p);
          p:=s;
          for i:=length(s)-1 downto 1 do p:=p+s[i];
          calc(p);
        end;
      end;
      if (length(s)=6)then exit;
      for i:=0 to 9 do 
        if (can[i])then rec(s+chr(i+48));
    end;

begin
  //assign(input,'in.txt');reset(input);
  //assign(output,'1.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(x);
    can[x]:=true;
  end;
  rec('');
  writeln(kans);
  for i:=1 to kans do writeln(ans[i]);
end.