{$R-,S-,Q-,I-,O+}
var
  tt,qq,ans,ii,rg,t,id,base,x,kd,kp,q,i,j,n: longint;
  ch: char;
  v: int64;
  b,max,d,p: array [0..36] of longint;
  pr: array [0..26,0..101,0..101] of longint;
  a: array [0..10010,0..26] of longint;
  u: array [3..16,0..262145,1..25] of byte;
  u2: array [0..4800010,1..25] of byte;
  ok: boolean;
  qw: int64;
begin
  kp:=0;
  for q:=2 to 100 do
  begin
    ok:=True;
    for i:=2 to q-1 do
      if q mod i = 0 then ok:=False;
    if ok then
    begin
      inc(kp);
      p[kp]:=q;
      for i:=0 to q-1 do
        for j:=0 to q-1 do pr[kp,i,j]:=(i*j) mod q;
    end;
  end;
  for base:=2 to 16 do
  begin
    x:=1; max[base]:=0;
    while x < 10000 do
    begin
      inc(max[base]);
      x:=x*base;
    end;
  end;
  fillchar(u,sizeof(u),1);
  fillchar(u2,sizeof(u2),1);
  read(n);
  for ii:=1 to n do
  begin
    read(qw);
    for j:=1 to kp do a[ii,j]:=qw mod p[j];
    for base:=2 to 16 do
    begin
      kd:=0; x:=ii-1;
      while kd < max[base] do
      begin
        inc(kd);
        d[kd]:=x mod base;
        x:=x div base;
      end;
      if base = 2 then rg:=7
      else rg:=kd;
      for t:=0 to 1 shl rg-1 do
      begin
        id:=0;
        for i:=kd downto 1 do
        begin
          id:=id*(base+1);
          if t and (1 shl (i-1)) <> 0 then id:=id+base
          else id:=id+d[i];
        end;
        for i:=1 to kp do
          if base > 2 then u[base,id,i]:=pr[i,u[base,id,i],a[ii,i]]
          else u2[id,i]:=pr[i,u2[id,i],a[ii,i]];
      end;
    end;
  end;
  read(tt);
  for qq:=1 to tt do
  begin
    read(base,ch);
    while not (ch in ['?','0'..'9','A'..'F']) do read(ch);
    kd:=0;
    while ch in ['?','0'..'9','A'..'F'] do
    begin
      inc(kd);
      if ch = '?' then d[kd]:=base else
      if ch in ['0'..'9'] then d[kd]:=Ord(ch)-48
      else d[kd]:=Ord(ch)-Ord('A')+10;
      read(ch);
    end;
    for i:=1 to kd shr 1 do
    begin
      j:=d[i]; d[i]:=d[kd-i+1]; d[kd-i+1]:=j;
    end;
    while kd < max[base] do
    begin
      inc(kd);
      d[kd]:=0;
    end;
    read(v);
    for i:=1 to 25 do b[i]:=1;
    ok:=True;
    if kd > max[base] then
      for j:=max[base]+1 to kd do
        if (d[j] <> 0) and (d[j] <> base) then ok:=False;
    if ok then
      if base > 2 then
      begin
        id:=0;
        for j:=max[base] downto 1 do id:=id*(base+1)+d[j];
        for i:=1 to 25 do b[i]:=u[base,id,i];
      end else
      begin
        for t:=0 to 1 shl 7-1 do
        begin
          id:=0; ok:=True;
          for i:=kd downto 1 do
          begin
            id:=id*3;
            if i > 7 then
            begin
              if d[i] = 2 then
              begin
                if t and (1 shl (i-8)) <> 0 then id:=id+1
                else id:=id+0;
              end else
              begin
                if (d[i] = 1) xor (t and (1 shl (i-8)) <> 0) then
                begin
                  ok:=False;
                  break;
                end;
                id:=id+d[i];
              end;
            end
            else id:=id+d[i];
          end;
          if ok then
            for i:=1 to kp do b[i]:=pr[i,b[i],u2[id,i]];
        end;
      end;
    ans:=-1;
    for i:=1 to 25 do
      if (b[i]+v) mod p[i] = 0 then
      begin
        ans:=p[i];
        break;
      end;
    writeln(ans);
  end;
end.